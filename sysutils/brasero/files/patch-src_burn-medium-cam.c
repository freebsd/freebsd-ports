--- src/burn-medium-cam.c.orig	2008-02-06 01:53:39.000000000 -0500
+++ src/burn-medium-cam.c	2008-02-06 01:56:01.000000000 -0500
@@ -0,0 +1,1925 @@
+/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 8; tab-width: 8 -*- */
+/*
+ * brasero
+ * Copyright (C) Philippe Rouquier 2007 <bonfire-app@wanadoo.fr>
+ * 		 Joe Marcus Clarke 2007 <marcus@FreeBSD.org>
+ *
+ * brasero is free software.
+ *
+ * You may redistribute it and/or modify it under the terms of the
+ * GNU General Public License, as published by the Free Software
+ * Foundation; either version 2 of the License, or (at your option)
+ * any later version.
+ *
+ * brasero is distributed in the hope that it will be useful,
+ * but WITHOUT ANY WARRANTY; without even the implied warranty of
+ * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
+ * See the GNU General Public License for more details.
+ *
+ * You should have received a copy of the GNU General Public License
+ * along with brasero.  If not, write to:
+ * 	The Free Software Foundation, Inc.,
+ * 	51 Franklin Street, Fifth Floor
+ * 	Boston, MA  02110-1301, USA.
+ */
+
+#ifdef HAVE_CONFIG_H
+#  include <config.h>
+#endif
+
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <stdlib.h>
+#include <fcntl.h>
+#include <errno.h>
+
+#include <glib.h>
+#include <glib/gi18n-lib.h>
+
+#include <nautilus-burn-drive.h>
+
+#include "burn-basics.h"
+#include "burn-debug.h"
+#include "burn-medium.h"
+#include "cam-cdrom.h"
+#include "scsi-read-format-capacities.h"
+#include "scsi-read-toc-pma-atip.h"
+#include "scsi-get-configuration.h"
+#include "scsi-q-subchannel.h"
+#include "scsi-utils.h"
+#include "freebsd_dvd_rw_utils.h"
+#include "burn-volume.h"
+#include "brasero-ncb.h"
+
+const gchar *icons [] = { 	"gnome-dev-removable",
+				"gnome-dev-cdrom",
+				"gnome-dev-disc-cdr",
+				"gnome-dev-disc-cdrw",
+				"gnome-dev-disc-dvdrom",
+				"gnome-dev-disc-dvdr",
+				"gnome-dev-disc-dvdrw",
+				"gnome-dev-disc-dvdr-plus",
+				"gnome-dev-disc-dvdram",
+				NULL };
+const gchar *types [] = {	N_("file"),
+				N_("CDROM"),
+				N_("CD-R"),
+				N_("CD-RW"),
+				N_("DVDROM"),
+				N_("DVD-R"),
+				N_("DVD-RW"),
+				N_("DVD+R"),
+				N_("DVD+RW"),
+				N_("DVD+R dual layer"),
+				N_("DVD+RW dual layer"),
+				N_("DVD-R dual layer"),
+				N_("DVD-RAM"),
+				N_("Blu-ray disc"),
+				N_("Writable Blu-ray disc"),
+				N_("Rewritable Blu-ray disc"),
+				NULL };
+
+
+typedef struct _BraseroMediumPrivate BraseroMediumPrivate;
+struct _BraseroMediumPrivate
+{
+	gint retry_id;
+
+	GSList * tracks;
+
+	const gchar *type;
+	const gchar *icon;
+
+	gint max_rd;
+	gint max_wrt;
+
+	gint *rd_speeds;
+	gint *wr_speeds;
+
+	gint64 block_num;
+	gint64 block_size;
+
+	guint64 next_wr_add;
+	BraseroMedia info;
+	NautilusBurnDrive * drive;
+};
+
+#define BRASERO_MEDIUM_PRIVATE(o)  (G_TYPE_INSTANCE_GET_PRIVATE ((o), BRASERO_TYPE_MEDIUM, BraseroMediumPrivate))
+
+enum
+{
+	PROP_0,
+	PROP_DRIVE
+};
+
+static GObjectClass* parent_class = NULL;
+
+const gchar *
+brasero_medium_get_type_string (BraseroMedium *medium)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+	return priv->type;
+}
+
+const gchar *
+brasero_medium_get_icon (BraseroMedium *medium)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+	return priv->icon;
+}
+
+BraseroMedia
+brasero_medium_get_status (BraseroMedium *medium)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+	return priv->info;
+}
+
+GSList *
+brasero_medium_get_tracks (BraseroMedium *medium)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+	return g_slist_copy (priv->tracks);
+}
+
+gboolean
+brasero_medium_get_last_data_track_address (BraseroMedium *medium,
+					    gint64 *byte,
+					    gint64 *sector)
+{
+	GSList *iter;
+	BraseroMediumPrivate *priv;
+	BraseroMediumTrack *track = NULL;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+
+	for (iter = priv->tracks; iter; iter = iter->next) {
+		BraseroMediumTrack *current;
+
+		current = iter->data;
+		if (current->type & BRASERO_MEDIUM_TRACK_DATA)
+			track = current;
+	}
+
+	if (!track) {
+		if (byte)
+			*byte = -1;
+		if (sector)
+			*sector = -1;
+		return FALSE;
+	}
+
+	if (byte)
+		*byte = track->start * priv->block_size;
+
+	if (sector)
+		*sector = track->start;
+
+	return TRUE;
+}
+
+gboolean
+brasero_medium_get_last_data_track_space (BraseroMedium *medium,
+					  gint64 *size,
+					  gint64 *blocks)
+{
+	GSList *iter;
+	BraseroMediumPrivate *priv;
+	BraseroMediumTrack *track = NULL;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+
+	for (iter = priv->tracks; iter; iter = iter->next) {
+		BraseroMediumTrack *current;
+
+		current = iter->data;
+		if (current->type & BRASERO_MEDIUM_TRACK_DATA)
+			track = current;
+	}
+
+	if (!track) {
+		if (size)
+			*size = -1;
+		if (blocks)
+			*blocks = -1;
+		return FALSE;
+	}
+
+	if (size)
+		*size = track->blocks_num * priv->block_size;
+	if (blocks)
+		*blocks = track->blocks_num;
+
+	return TRUE;
+}
+
+guint
+brasero_medium_get_track_num (BraseroMedium *medium)
+{
+	guint retval = 0;
+	GSList *iter;
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+	for (iter = priv->tracks; iter; iter = iter->next) {
+		BraseroMediumTrack *current;
+
+		current = iter->data;
+		if (current->type & BRASERO_MEDIUM_TRACK_LEADOUT)
+			break;
+
+		retval ++;
+	}
+
+	return retval;
+}
+
+static BraseroMediumTrack *
+brasero_medium_get_track (BraseroMedium *medium,
+			  guint num)
+{
+	guint i = 1;
+	GSList *iter;
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+
+	for (iter = priv->tracks; iter; iter = iter->next) {
+		BraseroMediumTrack *current;
+
+		current = iter->data;
+		if (current->type == BRASERO_MEDIUM_TRACK_LEADOUT)
+			break;
+
+		if (i == num)
+			return current;
+
+		i++;
+	}
+
+	return NULL;
+}
+
+gboolean
+brasero_medium_get_track_space (BraseroMedium *medium,
+				guint num,
+				gint64 *size,
+				gint64 *blocks)
+{
+	BraseroMediumPrivate *priv;
+	BraseroMediumTrack *track;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+
+	track = brasero_medium_get_track (medium, num);
+	if (!track) {
+		if (size)
+			*size = -1;
+		if (blocks)
+			*blocks = -1;
+		return FALSE;
+	}
+
+	if (size)
+		*size = track->blocks_num * priv->block_size;
+	if (blocks)
+		*blocks = track->blocks_num;
+
+	return TRUE;
+}
+
+gboolean
+brasero_medium_get_track_address (BraseroMedium *medium,
+				  guint num,
+				  gint64 *byte,
+				  gint64 *sector)
+{
+	BraseroMediumPrivate *priv;
+	BraseroMediumTrack *track;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+
+	track = brasero_medium_get_track (medium, num);
+	if (!track) {
+		if (byte)
+			*byte = -1;
+		if (sector)
+			*sector = -1;
+		return FALSE;
+	}
+
+	if (byte)
+		*byte = track->start * priv->block_size;
+	if (sector)
+		*sector = track->start;
+
+	return TRUE;
+}
+
+gint64
+brasero_medium_get_next_writable_address (BraseroMedium *medium)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+	return priv->next_wr_add;
+}
+
+gint64
+brasero_medium_get_max_write_speed (BraseroMedium *medium)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+	return priv->max_wrt * 1024;
+}
+
+/**
+ * NOTEs about the following functions:
+ * for all closed media (including ROM types) capacity == size of data and
+ * should be the size of all data on the disc, free space is 0
+ * for all blank -R types capacity == free space and size of data == 0
+ * for all multisession -R types capacity == free space since having the real
+ * capacity of the media would be useless as we can only use this type of media
+ * to append more data
+ * for all -RW types capacity = free space + size of data. Here they can be
+ * appended (use free space) or rewritten (whole capacity).
+ *
+ * Usually:
+ * the free space is the size of the leadout track
+ * the size of data is the sum of track sizes (excluding leadout)
+ * the capacity depends on the media:
+ * for closed discs == sum of track sizes
+ * for multisession discs == free space (leadout size)
+ * for blank discs == (free space) leadout size
+ * for rewritable/blank == use SCSI functions to get capacity (see below)
+ *
+ * In fact we should really need the size of data in DVD+/-RW cases since the
+ * session is always equal to the size of the disc.
+ */
+
+void
+brasero_medium_get_data_size (BraseroMedium *medium,
+			      gint64 *size,
+			      gint64 *blocks)
+{
+	GSList *iter;
+	BraseroMediumPrivate *priv;
+	BraseroMediumTrack *track = NULL;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+
+	if (!priv->tracks) {
+		/* that's probably because it wasn't possible to retrieve info */
+		if (size)
+			*size = 0;
+
+		if (blocks)
+			*blocks = 0;
+
+		return;
+	}
+
+	for (iter = priv->tracks; iter; iter = iter->next) {
+		BraseroMediumTrack *tmp;
+
+		tmp = iter->data;
+		if (tmp->type == BRASERO_MEDIUM_TRACK_LEADOUT)
+			break;
+
+		track = iter->data;
+	}
+
+	if (size)
+		*size = track ? (track->start + track->blocks_num) * priv->block_size: 0;
+
+	if (blocks)
+		*blocks = track ? track->start + track->blocks_num: 0;
+}
+
+void
+brasero_medium_get_free_space (BraseroMedium *medium,
+			       gint64 *size,
+			       gint64 *blocks)
+{
+	GSList *iter;
+	BraseroMediumPrivate *priv;
+	BraseroMediumTrack *track = NULL;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+
+	if (!priv->tracks) {
+		/* that's probably because it wasn't possible to retrieve info.
+		 * maybe it also happens with unformatted DVD+RW */
+
+		if (priv->info & BRASERO_MEDIUM_CLOSED) {
+			if (size)
+				*size = 0;
+
+			if (blocks)
+				*blocks = 0;
+		}
+		else {
+			if (size)
+				*size = priv->block_num * priv->block_size;
+
+			if (blocks)
+				*blocks = priv->block_num;
+		}
+
+		return;
+	}
+
+	for (iter = priv->tracks; iter; iter = iter->next) {
+		BraseroMediumTrack *tmp;
+
+		tmp = iter->data;
+		if (tmp->type == BRASERO_MEDIUM_TRACK_LEADOUT) {
+			track = iter->data;
+			break;
+		}
+	}
+
+	if (size) {
+		if (!track) {
+			/* No leadout was found so the disc is probably closed:
+			 * no free space left. */
+			*size = 0;
+		}
+		else if (track->blocks_num <= 0)
+			*size = (priv->block_num - track->start) * priv->block_size;
+		else
+			*size = track->blocks_num * priv->block_size;
+	}
+
+	if (blocks) {
+		if (!track) {
+			/* No leadout was found so the disc is probably closed:
+			 * no free space left. */
+			*blocks = 0;
+		}
+		else if (track->blocks_num <= 0)
+			*blocks = priv->block_num - track->blocks_num;
+		else
+			*blocks = track->blocks_num;
+	}
+}
+
+void
+brasero_medium_get_capacity (BraseroMedium *medium,
+			     gint64 *size,
+			     gint64 *blocks)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (medium);
+
+	if (priv->info & BRASERO_MEDIUM_REWRITABLE) {
+		if (size)
+			*size = priv->block_num * priv->block_size;
+
+		if (blocks)
+			*blocks = priv->block_num;
+	}
+	else  if (priv->info & BRASERO_MEDIUM_CLOSED)
+		brasero_medium_get_data_size (medium, size, blocks);
+	else
+		brasero_medium_get_free_space (medium, size, blocks);
+}
+
+/**
+ * Function to retrieve the capacity of a media
+ */
+
+static BraseroBurnResult
+brasero_medium_get_capacity_CD_RW (BraseroMedium *self,
+				   BRASEROCDROM *cdrom)
+{
+	unsigned char *atip_data = NULL;
+	unsigned char *desc;
+	BraseroMediumPrivate *priv;
+	int result;
+	int size;
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	BRASERO_BURN_LOG ("Retrieving capacity from atip");
+
+	result = brasero_cdrom_read_atip (cdrom, &atip_data);
+
+	if (result != 0) {
+		g_free (atip_data);
+
+		BRASERO_BURN_LOG ("READ ATIP failed (scsi error)");
+		return BRASERO_BURN_ERR;
+	}
+
+	size = (atip_data[0] << 8 | atip_data[1]) - 2;
+
+	/* check the size of the structure: it must be at least 16 bytes long */
+	if (size < 16) {
+		if (size)
+			g_free (atip_data);
+
+		BRASERO_BURN_LOG ("READ ATIP failed (wrong size)");
+		return BRASERO_BURN_ERR;
+	}
+
+	desc = atip_data + 8;
+
+	priv->block_num = BRASERO_MSF_TO_LBA (desc[8], desc[9], desc[10]);
+	g_free (atip_data);
+
+	BRASERO_BURN_LOG ("Format capacity %lli %lli",
+			  priv->block_num,
+			  priv->block_size);
+
+	return BRASERO_BURN_OK;
+}
+
+static BraseroBurnResult
+brasero_medium_get_capacity_DVD_RW (BraseroMedium *self,
+				    BRASEROCDROM *cdrom)
+{
+	unsigned char *hdr = NULL;
+	unsigned char *current;
+	BraseroMediumPrivate *priv;
+	int result;
+
+	BRASERO_BURN_LOG ("Retrieving format capacity");
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+	result = brasero_cdrom_read_format_capacities (cdrom, &hdr);
+	if (result != 0) {
+		g_free (hdr);
+
+		BRASERO_BURN_LOG ("READ FORMAT CAPACITIES failed");
+		return BRASERO_BURN_ERR;
+	}
+
+	current = hdr + 5;
+
+	/* see if the media is already formatted */
+	if ((current[4] & 3) != BRASERO_SCSI_DESC_FORMATTED) {
+		int i, max;
+		unsigned char *desc;
+
+		max = (hdr[4] - 8) / 8;
+
+		desc = hdr + 5;
+		for (i = 0; i < max; i ++, desc += 8) {
+			/* search for the correct descriptor */
+			if (BRASERO_MEDIUM_IS (priv->info, BRASERO_MEDIUM_DVDRW_PLUS)) {
+				if ((desc[4] >> 2) == BRASERO_SCSI_DVDRW_PLUS) {
+					priv->block_num = (desc[0] << 24 | desc[1] << 16 | desc[2] << 8 | desc[3]);
+					priv->block_size = (desc[5] << 16 | desc[6] << 8 | desc[7]);
+
+					/* that can happen */
+					if (!priv->block_size)
+						priv->block_size = 2048;
+					break;
+				}
+			}
+			else if ((desc[4] >> 2) == BRASERO_SCSI_BLOCK_SIZE_DEFAULT_AND_DB) {
+				priv->block_num = (desc[0] << 24 | desc[1] << 16 | desc[2] << 8 | desc[3]);
+				priv->block_size = (desc[5] << 16 | desc[6] << 8 | desc[7]);
+				break;
+			}
+		}
+	}
+	else {
+		priv->block_num = (current[0] << 24 | current[1] << 16 | current[2] << 8 | current[3]);
+		priv->block_size = (current[5] << 16 | current[6] << 8 | current[7]);
+	}
+
+	BRASERO_BURN_LOG ("Format capacity %lli %lli",
+			  priv->block_num,
+			  priv->block_size);
+
+	g_free (hdr);
+	return BRASERO_BURN_OK;
+}
+
+static BraseroBurnResult
+brasero_medium_get_capacity_by_type (BraseroMedium *self,
+				     BRASEROCDROM *cdrom)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	priv->block_size = 2048;
+
+	if (!(priv->info & BRASERO_MEDIUM_REWRITABLE))
+		return BRASERO_BURN_OK;
+
+	if (priv->info & BRASERO_MEDIUM_CD)
+		brasero_medium_get_capacity_CD_RW (self, cdrom);
+	else
+		brasero_medium_get_capacity_DVD_RW (self, cdrom);
+
+	return BRASERO_BURN_OK;
+}
+
+/**
+ * Functions to retrieve the speed
+ */
+
+static BraseroBurnResult
+brasero_medium_get_speed_mmc3 (BraseroMedium *self,
+			       BRASEROCDROM *cdrom)
+{
+	int size;
+	int num_desc, i;
+	gint max_rd, max_wrt;
+	int result;
+	BraseroMediumPrivate *priv;
+	unsigned char *desc;
+	unsigned char *wrt_perf = NULL;
+
+	BRASERO_BURN_LOG ("Retrieving speed (Get Performance)");
+
+	/* NOTE: this only work if there is RT streaming feature with
+	 * wspd bit set to 1. At least an MMC3 drive. */
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+	result = brasero_cdrom_get_performance_wrt_spd_desc (cdrom, &wrt_perf);
+
+	if (result != 0) {
+		g_free (wrt_perf);
+
+		BRASERO_BURN_LOG ("GET PERFORMANCE failed");
+		return BRASERO_BURN_ERR;
+	}
+
+	size = 4 + (wrt_perf[0] << 24 | wrt_perf[1] << 16 | wrt_perf[2] << 8 | wrt_perf[3]);
+
+	num_desc = (size - 8) / 16;
+
+	if (num_desc <=  0)
+		goto end;
+
+	priv->rd_speeds = g_new0 (gint, num_desc + 1);
+	priv->wr_speeds = g_new0 (gint, num_desc + 1);
+
+	max_rd = 0;
+	max_wrt = 0;
+
+	desc = wrt_perf + 8;
+	for (i = 0; i < num_desc; i ++, desc += 16) {
+		priv->rd_speeds [i] = (desc[8] << 24 | desc[9] << 16 | desc[10] << 8 || desc[11]);
+		priv->wr_speeds [i] = (desc[12] << 24 | desc[13] << 16 | desc[14] << 8 | desc[15]);
+
+		max_rd = MAX (max_rd, priv->rd_speeds [i]);
+		max_wrt = MAX (max_wrt, priv->wr_speeds [i]);
+	}
+
+	priv->max_rd = max_rd;
+	priv->max_wrt = max_wrt;
+
+end:
+
+	g_free (wrt_perf);
+
+	/* strangely there are so drives (I know one case) which support this
+	 * function but don't report any speed. So if our top speed is 0 then
+	 * use the other way to get the speed. It was a Teac */
+	if (!priv->max_wrt)
+		return BRASERO_BURN_ERR;
+
+	return BRASERO_BURN_OK;
+}
+
+static BraseroBurnResult
+brasero_medium_get_page_2A_write_speed_desc (BraseroMedium *self,
+					     BRASEROCDROM *cdrom)
+{
+	BraseroMediumPrivate *priv;
+	int result;
+	char *wspeeds;
+	int rspeed, wspeed;
+
+	BRASERO_BURN_LOG ("Retrieving speed (2A speeds)");
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+	result = brasero_cdrom_get_read_write_speed (cdrom, &rspeed, &wspeed, &wspeeds);
+
+	if (result != 0) {
+		BRASERO_BURN_LOG ("MODE SENSE failed");
+		return BRASERO_BURN_ERR;
+	}
+
+	if (wspeeds != NULL) {
+		char **speedv;
+		int i;
+
+		speedv = g_strsplit_set (wspeeds, ",", 0);
+		g_free (wspeeds);
+		priv->wr_speeds = g_new0 (gint, g_strv_length (speedv) + 1);
+		for (i = 0; speedv[i] != NULL; i++) {
+			if (*(speedv[i]))
+				priv->wr_speeds[i] = atoi (speedv[i]);
+		}
+		g_strfreev (speedv);
+	}
+
+	priv->max_wrt = wspeed;
+	priv->max_rd = rspeed;
+
+	return BRASERO_BURN_OK;
+}
+
+static BraseroBurnResult
+brasero_medium_get_page_2A_max_speed (BraseroMedium *self,
+				      BRASEROCDROM *cdrom)
+{
+	BraseroMediumPrivate *priv;
+	int result;
+	int rspeed, wspeed;
+	char *wspeeds;
+
+	BRASERO_BURN_LOG ("Retrieving speed (2A max)");
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	result = brasero_cdrom_get_read_write_speed (cdrom, &rspeed, &wspeed, &wspeeds);
+
+	if (result != 0) {
+		BRASERO_BURN_LOG ("MODE SENSE failed");
+		return BRASERO_BURN_ERR;
+	}
+
+	priv->max_rd = rspeed;
+	priv->max_wrt = wspeed;
+
+	g_free (wspeeds);
+
+	return BRASERO_BURN_OK;
+}
+
+static BraseroBurnResult
+brasero_medium_get_medium_type (BraseroMedium *self,
+				BRASEROCDROM *cdrom)
+{
+	unsigned char *hdr = NULL;
+	unsigned char *confdesc;
+	BraseroMediumPrivate *priv;
+	BraseroBurnResult result;
+	int profile;
+	int res;
+
+	BRASERO_BURN_LOG ("Retrieving media profile");
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+	res = brasero_cdrom_get_configuration_feature (cdrom,
+						       BRASERO_SCSI_FEAT_REAL_TIME_STREAM,
+						       &hdr);
+	if (res != 0) {
+		unsigned char *data = NULL;
+		unsigned char *desc;
+		int size;
+
+		BRASERO_BURN_LOG ("GET CONFIGURATION failed");
+
+		/* This could be a MMC1 drive since this command was
+		 * introduced in MMC2 and is supported onward. So it
+		 * has to be a CD (R/RW). The rest of the information
+		 * will be provided by read_disc_information. */
+
+		/* The only thing here left to determine is if that's a WRITABLE
+		 * or a REWRITABLE. To determine that information, we need to
+		 * read TocPmaAtip. It if fails that's a ROM, if it succeeds.
+		 */
+		res = brasero_cdrom_read_atip (cdrom, &data);
+		if (res != 0) {
+			/* CDROM */
+			priv->info = BRASERO_MEDIUM_CDROM;
+			priv->type = types [1];
+			priv->icon = icons [1];
+		}
+		else {
+			/* check the size of the structure: it must be at least 8 bytes long */
+			size = (data[0] << 8 | data[1]) - 2;
+			if (size < 8) {
+				if (size)
+					g_free (data);
+
+				BRASERO_BURN_LOG ("READ ATIP failed (wrong size)");
+				return BRASERO_BURN_ERR;
+			}
+
+			desc = data + 4;
+
+			if ((desc[2] >> 6) & 1) {
+				/* CDRW */
+				priv->info = BRASERO_MEDIUM_CDRW;
+				priv->type = types [3];
+				priv->icon = icons [3];
+			}
+			else {
+				/* CDR */
+				priv->info = BRASERO_MEDIUM_CDR;
+				priv->type = types [2];
+				priv->icon = icons [2];
+			}
+
+			g_free (data);
+		}
+
+		/* retrieve the speed */
+		result = brasero_medium_get_page_2A_max_speed (self, cdrom);
+		return result;
+	}
+
+	profile = (hdr[6] << 8 | hdr[7]);
+
+	switch (profile) {
+	case BRASERO_SCSI_PROF_CDROM:
+		priv->info = BRASERO_MEDIUM_CDROM;
+		priv->type = types [1];
+		priv->icon = icons [1];
+		break;
+
+	case BRASERO_SCSI_PROF_CDR:
+		priv->info = BRASERO_MEDIUM_CDR;
+		priv->type = types [2];
+		priv->icon = icons [2];
+		break;
+
+	case BRASERO_SCSI_PROF_CDRW:
+		priv->info = BRASERO_MEDIUM_CDRW;
+		priv->type = types [3];
+		priv->icon = icons [3];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_ROM:
+		priv->info = BRASERO_MEDIUM_DVD_ROM;
+		priv->type = types [4];
+		priv->icon = icons [4];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_R:
+		priv->info = BRASERO_MEDIUM_DVDR;
+		priv->type = types [5];
+		priv->icon = icons [5];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_RW_RESTRICTED:
+		priv->info = BRASERO_MEDIUM_DVDRW_RESTRICTED;
+		priv->type = types [6];
+		priv->icon = icons [6];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_RW_SEQUENTIAL:
+		priv->info = BRASERO_MEDIUM_DVDRW;
+		priv->type = types [6];
+		priv->icon = icons [6];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_R_PLUS:
+		priv->info = BRASERO_MEDIUM_DVDR_PLUS;
+		priv->type = types [7];
+		priv->icon = icons [7];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_RW_PLUS:
+		priv->info = BRASERO_MEDIUM_DVDRW_PLUS;
+		priv->type = types [8];
+		priv->icon = icons [7];
+		break;
+
+	/* WARNING: these types are recognized, no more */
+	case BRASERO_SCSI_PROF_DVD_R_PLUS_DL:
+		priv->info = BRASERO_MEDIUM_DVDR_PLUS_DL;
+		priv->type = types [9];
+		priv->icon = icons [7];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_RW_PLUS_DL:
+		priv->info = BRASERO_MEDIUM_DVDRW_PLUS_DL;
+		priv->type = types [10];
+		priv->icon = icons [7];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_R_DL_SEQUENTIAL:
+		priv->info = BRASERO_MEDIUM_DVDR_DL;
+		priv->type = types [11];
+		priv->icon = icons [5];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_R_DL_JUMP:
+		priv->info = BRASERO_MEDIUM_DVDR_JUMP_DL;
+		priv->type = types [11];
+		priv->icon = icons [5];
+		break;
+
+	case BRASERO_SCSI_PROF_DVD_RAM:
+		priv->info = BRASERO_MEDIUM_DVD_RAM;
+		priv->type = types [12];
+		priv->icon = icons [8];
+		break;
+
+	case BRASERO_SCSI_PROF_BD_ROM:
+		priv->info = BRASERO_MEDIUM_BD_ROM;
+		priv->type = types [13];
+		priv->icon = icons [4];
+		break;
+
+	case BRASERO_SCSI_PROF_BR_R_SEQUENTIAL:
+		priv->info = BRASERO_MEDIUM_BDR;
+		priv->type = types [14];
+		priv->icon = icons [5];
+		break;
+
+	case BRASERO_SCSI_PROF_BR_R_RANDOM:
+		priv->info = BRASERO_MEDIUM_BDR_RANDOM;
+		priv->type = types [14];
+		priv->icon = icons [5];
+		break;
+
+	case BRASERO_SCSI_PROF_BD_RW:
+		priv->info = BRASERO_MEDIUM_BDRW;
+		priv->type = types [15];
+		priv->icon = icons [6];
+		break;
+
+	case BRASERO_SCSI_PROF_NON_REMOVABLE:
+	case BRASERO_SCSI_PROF_REMOVABLE:
+	case BRASERO_SCSI_PROF_MO_ERASABLE:
+	case BRASERO_SCSI_PROF_MO_WRITE_ONCE:
+	case BRASERO_SCSI_PROF_MO_ADVANCED_STORAGE:
+	case BRASERO_SCSI_PROF_DDCD_ROM:
+	case BRASERO_SCSI_PROF_DDCD_R:
+	case BRASERO_SCSI_PROF_DDCD_RW:
+	case BRASERO_SCSI_PROF_HD_DVD_ROM:
+	case BRASERO_SCSI_PROF_HD_DVD_R:
+	case BRASERO_SCSI_PROF_HD_DVD_RAM:
+		priv->info = BRASERO_MEDIUM_UNSUPPORTED;
+		priv->icon = icons [0];
+		g_free (hdr);
+		return BRASERO_BURN_NOT_SUPPORTED;
+	}
+
+	confdesc = hdr + 8;
+
+	/* try all SCSI functions to get write/read speeds in order */
+	if (confdesc[4] >= 4) {
+		unsigned char *stream;
+
+		/* means it's at least an MMC3 drive */
+		stream = confdesc + 5;
+		if ((stream[0] >> 1) & 1) {
+			result = brasero_medium_get_speed_mmc3 (self, cdrom);
+			if (result == BRASERO_BURN_OK)
+				goto end;
+		}
+
+		if ((stream[0] >> 2) & 1) {
+			result = brasero_medium_get_page_2A_write_speed_desc (self, cdrom);
+			if (result == BRASERO_BURN_OK)
+				goto end;
+		}
+	}
+
+	/* fallback for speeds */
+	result = brasero_medium_get_page_2A_max_speed (self, cdrom);
+
+end:
+
+	g_free (hdr);
+
+	if (result != BRASERO_BURN_OK)
+		return result;
+
+	return BRASERO_BURN_OK;
+}
+
+static BraseroBurnResult
+brasero_medium_get_css_feature (BraseroMedium *self,
+				BRASEROCDROM *cdrom)
+{
+	unsigned char *hdr = NULL;
+	BraseroMediumPrivate *priv;
+	int result;
+	int size;
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	BRASERO_BURN_LOG ("Testing for Css encrypted media");
+	result = brasero_cdrom_get_configuration_feature (cdrom,
+							  BRASERO_SCSI_FEAT_DVD_CSS,
+							  &hdr);
+	if (result != 0) {
+		g_free (hdr);
+
+		BRASERO_BURN_LOG ("GET CONFIGURATION failed");
+		return BRASERO_BURN_ERR;
+	}
+
+	size = 4 + (hdr[0] << 24 | hdr[1] << 16 | hdr[2] << 8 | hdr[3]);
+
+	if (size < 9 || hdr[12] < 4) {
+		g_free (hdr);
+		return BRASERO_BURN_OK;
+	}
+
+	/* here we just need to see if this feature is current or not */
+	if (hdr[11] & 1) {
+		priv->info |= BRASERO_MEDIUM_PROTECTED;
+		BRASERO_BURN_LOG ("media is Css protected");
+	}
+
+	g_free (hdr);
+	return BRASERO_BURN_OK;
+}
+
+/**
+ * Functions to get information about disc contents
+ */
+
+static void
+brasero_medium_set_track_type (BraseroMedium *self,
+			       BraseroMediumTrack *track,
+			       guchar control)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	if (control & BRASERO_SCSI_TRACK_COPY)
+		track->type |= BRASERO_MEDIUM_TRACK_COPY;
+
+	if (!(control & BRASERO_SCSI_TRACK_DATA)) {
+		track->type |= BRASERO_MEDIUM_TRACK_AUDIO;
+		priv->info |= BRASERO_MEDIUM_HAS_AUDIO;
+
+		if (control & BRASERO_SCSI_TRACK_PREEMP)
+			track->type |= BRASERO_MEDIUM_TRACK_PREEMP;
+
+		if (control & BRASERO_SCSI_TRACK_4_CHANNELS)
+			track->type |= BRASERO_MEDIUM_TRACK_4_CHANNELS;
+	}
+	else {
+		track->type |= BRASERO_MEDIUM_TRACK_DATA;
+		priv->info |= BRASERO_MEDIUM_HAS_DATA;
+
+		if (control & BRASERO_SCSI_TRACK_DATA_INCREMENTAL)
+			track->type |= BRASERO_MEDIUM_TRACK_INCREMENTAL;
+	}
+}
+
+static BraseroBurnResult
+brasero_medium_track_volume_size (BraseroMedium *self,
+				  BraseroMediumTrack *track,
+				  BRASEROCDROM *cdrom)
+{
+	BraseroMediumPrivate *priv;
+	BraseroBurnResult res;
+	GError *error = NULL;
+	gint64 nb_blocks;
+
+	if (!track)
+		return BRASERO_BURN_ERR;
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	/* This is a special case. For DVD+RW and DVD-RW in restricted
+	 * mode, there is only one session that takes the whole disc size
+	 * once formatted. That doesn't necessarily means they have data
+	 * Note also that they are reported as complete though you can
+	 * still add data (with growisofs). It is nevertheless on the
+	 * condition that the fs is valid.
+	 * So we check if their first and only volume is valid.
+	 * That's also used when the track size is reported a 300 Kio
+	 * see below */
+	res = brasero_volume_get_size_fd (brasero_cdrom_get_fd (cdrom),
+					  track->start,
+					  &nb_blocks,
+					  NULL);
+	if (!res) {
+		BRASERO_BURN_LOG ("Failed to retrieve the volume size: %s",
+				  error && error->message ?
+				  error->message:"unknown error");
+
+		if (error)
+			g_error_free (error);
+		return BRASERO_BURN_ERR;
+	}
+
+	track->blocks_num = nb_blocks;
+	return BRASERO_BURN_OK;
+}
+
+static BraseroBurnResult
+brasero_medium_track_get_info (BraseroMedium *self,
+			       BraseroMediumTrack *track,
+			       int track_num,
+			       BRASEROCDROM *cdrom)
+{
+	unsigned char track_info[48];
+	BraseroMediumPrivate *priv;
+	int result;
+	int size;
+	int next_wrt;
+
+	BRASERO_BURN_LOG ("Retrieving track information for %i", track_num);
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	/* at this point we know the type of the disc that's why we set the
+	 * size according to this type. That may help to avoid outrange address
+	 * errors. */
+	if (BRASERO_MEDIUM_IS (priv->info, BRASERO_MEDIUM_DL|BRASERO_MEDIUM_WRITABLE))
+		size = 48;
+	else if (BRASERO_MEDIUM_IS (priv->info, BRASERO_MEDIUM_PLUS|BRASERO_MEDIUM_WRITABLE))
+		size = 40;
+	else
+		size = 36;
+
+	result = brasero_cdrom_read_track_info (cdrom, track_num, track_info, size);
+
+	if (result != 0) {
+		BRASERO_BURN_LOG ("READ TRACK INFO failed");
+		return BRASERO_BURN_ERR;
+	}
+
+	track->blocks_num = (track_info[24] << 24 | track_info[25] << 16 | track_info[26] << 8 | track_info[27]);
+	track->session = (track_info[33] << 8 | track_info[3]);
+
+	/* Now here is a potential bug: we can write tracks (data or not)
+	 * shorter than 300 Kio /2 sec but they will be padded to reach this
+	 * floor value. That means that is blocks_num is 300 blocks that may
+	 * mean that the data length on the track is actually shorter.
+	 * So we read the volume descriptor. If it works, good otherwise
+	 * use the old value.
+	 * That's important for checksuming to have a perfect account of the
+	 * data size. */
+	if (track->blocks_num <= 300) {
+		BRASERO_BURN_LOG ("300 sectors size. Checking for real size");
+		brasero_medium_track_volume_size (self, track, cdrom);
+	}
+
+	next_wrt = (track_info[12] << 24 | track_info[13] << 16 | track_info[14] << 7 | track_info[15]);
+
+	if (next_wrt);
+		priv->next_wr_add = next_wrt;
+
+	BRASERO_BURN_LOG ("Track %i (session %i): type = %i start = %llu size = %llu",
+			  track_num,
+			  track->session,
+			  track->type,
+			  track->start,
+			  track->blocks_num);
+
+	return BRASERO_BURN_OK;
+}
+
+/**
+ * return :
+ *  0 when it's not possible to determine (fallback to formatted toc)
+ * -1 for BCD
+ *  1 for HEX */
+static guint
+brasero_medium_check_BCD_use (BraseroMedium *self,
+			      BRASEROCDROM *cdrom,
+			      unsigned char *desc,
+			      guint num)
+{
+	guint i;
+	int size;
+	guint leadout = 0;
+	guint track_num = 0;
+	gboolean use_BCD = TRUE;
+	gboolean use_HEX = TRUE;
+	int result;
+	unsigned char *dptr;
+	unsigned char track_info[48];
+	guint start_BCD, start_LBA, track_start;
+
+	/* first check if all values are valid BCD numbers in the descriptors */
+	dptr = desc;
+	for (i = 0; i < num; i++, dptr += 11) {
+		if ((dptr[1] >> 4) == 1 && dptr[3] <= BRASERO_SCSI_Q_SUB_CHANNEL_TRACK_START) {
+			if (!BRASERO_IS_BCD_VALID (dptr[8])
+			||  !BRASERO_IS_BCD_VALID (dptr[9])
+			||  !BRASERO_IS_BCD_VALID (dptr[10])) {
+				use_BCD = FALSE;
+				break;
+			}
+		}
+		else if (dptr[3] == BRASERO_SCSI_Q_SUB_CHANNEL_LEADOUT_START) {
+			if (!BRASERO_IS_BCD_VALID (dptr[8])
+			||  !BRASERO_IS_BCD_VALID (dptr[9])
+			||  !BRASERO_IS_BCD_VALID (dptr[10])) {
+				use_BCD = FALSE;
+				break;
+			}
+		}
+	}
+
+	/* then check if there are valid Hex values */
+	dptr = desc;
+	for (i = 0; i < num; i++, dptr += 11) {
+		if ((dptr[i] >> 4) != 1 || dptr[3] > BRASERO_SCSI_Q_SUB_CHANNEL_TRACK_START)
+			continue;
+
+		if (dptr[8] > 99
+		||  dptr[9] > 59
+		||  dptr[10] > 74) {
+			use_HEX = FALSE;
+			break;
+		}
+	}
+
+	if (use_BCD != use_HEX) {
+		if (use_BCD)
+			return -1;
+
+		return 1;
+	}
+
+	/* To check if the drive uses BCD values or HEX values we ask for the
+	 * track information that contains also the start for the track but in
+	 * HEX values. If values are the same then it works. */
+
+	/* NOTE: there could be another way to do it: get first track, in LBA
+	 * and BCD it must be 150. */
+
+	/* First find the first track and get track start address in BCD */
+	BRASERO_BURN_LOG ("Retrieving track information to determine number format");
+
+	dptr = desc;
+	for (i = 0; i < num; i++, dptr += 11) {
+			if ((dptr[1] >> 4) == BRASERO_SCSI_Q_SUB_CHANNEL_LEADIN_MODE5
+			&&  dptr[3] == BRASERO_SCSI_Q_SUB_CHANNEL_MULTI_NEXT_SESSION) {
+			/* store the leadout number just in case */
+			leadout = i;
+			continue;
+		}
+
+		if ((dptr[1] >> 4) != 1 || dptr[3] > BRASERO_SCSI_Q_SUB_CHANNEL_TRACK_START)
+			continue;
+
+		track_num ++;
+
+		start_BCD = BRASERO_MSF_TO_LBA (BRASERO_GET_BCD (dptr[8]),
+						BRASERO_GET_BCD (dptr[9]),
+						BRASERO_GET_BCD (dptr[10]));
+
+		start_LBA = BRASERO_MSF_TO_LBA (dptr[8], dptr[9], dptr[10]);
+
+		BRASERO_BURN_LOG ("Comparing to track information from READ TRACK INFO for track %i", track_num);
+
+		size = 36;
+		start_LBA -= 150;
+		start_BCD -= 150;
+
+		result = brasero_cdrom_read_track_info (cdrom,
+						        track_num,
+						        track_info,
+							size);
+
+		if (result != 0) {
+			BRASERO_BURN_LOG ("READ TRACK INFO failed");
+			/* Fallback to formatted toc */
+			return 0;
+		}
+
+		track_start = (track_info[8] << 24 | track_info[9] << 16 | track_info[10] << 8 | track_info[11]);
+		BRASERO_BURN_LOG ("comparing DCB %i and LBA %i to real start address %i",
+				  start_BCD, start_LBA, track_start);
+
+		/* try to find a conclusive match */
+		if (track_start == start_BCD && track_start != start_LBA)
+			return -1;
+
+		if (track_start == start_LBA && track_start != start_BCD)
+			return 1;
+	}
+
+	/* Our last chance, the leadout.
+	 * NOTE: no need to remove 150 sectors here. */
+	dptr = desc + (leadout * 11);
+	start_BCD = BRASERO_MSF_TO_LBA (BRASERO_GET_BCD (dptr[4]),
+					BRASERO_GET_BCD (dptr[5]),
+					BRASERO_GET_BCD (dptr[6]));
+
+	start_LBA = BRASERO_MSF_TO_LBA (dptr[4], dptr[5], dptr[6]);
+
+	BRASERO_BURN_LOG ("Comparing to track information from READ TRACK INFO for leadout");
+
+	size = 36;
+
+	/* leadout number is number of tracks + 1 */
+	result = brasero_cdrom_read_track_info (cdrom,
+					        track_num + 1,
+					        track_info,
+						size);
+
+	if (result != 0) {
+		BRASERO_BURN_LOG ("READ TRACK INFO failed for leadout");
+		/* Fallback to formatted toc */
+		return 0;
+	}
+
+	track_start = (track_info[8] << 24 | track_info[9] << 16 | track_info[10] << 8 | track_info[11]);
+	BRASERO_BURN_LOG ("comparing DCB %i and LBA %i to real start address %i",
+			  start_BCD, start_LBA, track_start);
+
+	/* try to find a conclusive match */
+	if (track_start == start_BCD && track_start != start_LBA)
+		return -1;
+
+	if (track_start == start_LBA && track_start != start_BCD)
+		return 1;
+
+	/* fallback to formatted toc */
+	return 0;
+}
+
+/**
+ * The reason why we use this perhaps more lengthy method is that with
+ * multisession discs, the first track is reported to be two sectors shorter
+ * than it should. As I don't know why and since the following works we use
+ * this one. */
+static BraseroBurnResult
+brasero_medium_get_CD_sessions_info (BraseroMedium *self,
+				     BRASEROCDROM *cdrom)
+{
+	gint use_bcd;
+	GSList *iter;
+	int num, i, size, res;
+	gint leadout_start = 0;
+	BraseroMediumPrivate *priv;
+	unsigned char *desc;
+	unsigned char *toc = NULL;
+
+	BRASERO_BURN_LOG ("Reading Raw Toc");
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	res = brasero_cdrom_read_toc_raw (cdrom, 0, &toc);
+	if (res != 0) {
+		BRASERO_BURN_LOG ("READ TOC failed");
+		return BRASERO_BURN_ERR;
+	}
+
+	size = (toc[0] << 8 | toc[1]) - 2;
+	num = size / 11;
+
+	BRASERO_BURN_LOG ("%i track(s) found", num);
+
+	desc = toc + 4;
+	use_bcd = brasero_medium_check_BCD_use (self, cdrom, desc, num);
+	if (!use_bcd) {
+		g_free (toc);
+
+		BRASERO_BURN_LOG ("Fallback to formatted toc");
+		return BRASERO_BURN_ERR;
+	}
+
+	if (use_bcd > 0)
+		use_bcd = 0;
+
+	if (use_bcd) {
+		BRASERO_BURN_LOG ("Using BCD format");
+	}
+	else {
+		BRASERO_BURN_LOG ("Using HEX format");
+	}
+
+	for (i = 0; i < num; i++, desc += 11) {
+		BraseroMediumTrack *track;
+
+		track = NULL;
+		if ((desc[1] >> 4) == 1 && desc[3] <= BRASERO_SCSI_Q_SUB_CHANNEL_TRACK_START) {
+			track = g_new0 (BraseroMediumTrack, 1);
+			track->session = desc[0];
+
+			brasero_medium_set_track_type (self, track, (desc[1] & 15));
+			if (use_bcd)
+				track->start = BRASERO_MSF_TO_LBA (BRASERO_GET_BCD (desc[8]),
+								   BRASERO_GET_BCD (desc[9]),
+								   BRASERO_GET_BCD (desc[10]));
+			else
+				track->start = BRASERO_MSF_TO_LBA (desc[8],
+								   desc[9],
+								   desc[10]);
+
+			track->start -= 150;
+
+			/* if there are tracks and the last previously added track is in
+			 * the same session then set the size */
+			if (priv->tracks) {
+				BraseroMediumTrack *last_track;
+
+				last_track = priv->tracks->data;
+				if (last_track->session == track->session)
+					last_track->blocks_num = track->start - last_track->start;
+			}
+
+			priv->tracks = g_slist_prepend (priv->tracks, track);
+		}
+		else if (desc[3] == BRASERO_SCSI_Q_SUB_CHANNEL_LEADOUT_START) {
+			/* NOTE: the leadout session is first in the list. So if
+			 * we have tracks in the list set the last session track
+			 * size when we reach a new leadout (and therefore a new
+			 * session). */
+
+			if (priv->tracks) {
+				BraseroMediumTrack *last_track;
+
+				last_track = priv->tracks->data;
+				last_track->blocks_num = leadout_start - last_track->start;
+			}
+
+			if (use_bcd)
+				leadout_start = BRASERO_MSF_TO_LBA (BRASERO_GET_BCD (desc[8]),
+								    BRASERO_GET_BCD (desc[9]),
+								    BRASERO_GET_BCD (desc[10]));
+			else
+				leadout_start = BRASERO_MSF_TO_LBA (desc[8],
+								    desc[9],
+								    desc[10]);
+			leadout_start -= 150;
+		}
+	}
+
+	if (priv->tracks) {
+		BraseroMediumTrack *last_track;
+
+		/* set the last found track size */
+		last_track = priv->tracks->data;
+		last_track->blocks_num = leadout_start - last_track->start;
+	}
+
+	/* Add a leadout */
+	if (!(priv->info & BRASERO_MEDIUM_CLOSED)) {
+		BraseroMediumTrack *track;
+
+		/* we shouldn't request info on leadout if the disc is closed */
+		track = g_new0 (BraseroMediumTrack, 1);
+		priv->tracks = g_slist_prepend (priv->tracks, track);
+		track->start = leadout_start;
+		track->type = BRASERO_MEDIUM_TRACK_LEADOUT;
+
+		brasero_medium_track_get_info (self, track, g_slist_length (priv->tracks), cdrom);
+	}
+
+	priv->tracks = g_slist_reverse (priv->tracks);
+
+	for (iter = priv->tracks; iter; iter = iter->next) {
+		BraseroMediumTrack *track;
+
+		track = iter->data;
+
+		/* check for tracks less that 300 sectors */
+		if (track->blocks_num <= 300 && track->type != BRASERO_MEDIUM_TRACK_LEADOUT) {
+			BRASERO_BURN_LOG ("300 sectors size. Checking for real size");
+			brasero_medium_track_volume_size (self, track, cdrom);
+		}
+
+		BRASERO_BURN_LOG ("Track %i: type = %i start = %llu size = %llu",
+				  g_slist_index (priv->tracks, track),
+				  track->type,
+				  track->start,
+				  track->blocks_num);
+	}
+
+	g_free (toc);
+	return BRASERO_BURN_OK;
+}
+
+/**
+ * NOTE: for DVD-R multisession we lose 28688 blocks for each session
+ * so the capacity is the addition of all session sizes + 28688 for each
+ * For all multisession DVD-/+R and CDR-RW the remaining size is given
+ * in the leadout. One exception though with DVD+/-RW.
+ */
+
+static void
+brasero_medium_add_DVD_plus_RW_leadout (BraseroMedium *self,
+					gint32 start)
+{
+	BraseroMediumTrack *leadout;
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	leadout = g_new0 (BraseroMediumTrack, 1);
+	priv->tracks = g_slist_append (priv->tracks, leadout);
+
+	leadout->start = start;
+	leadout->type = BRASERO_MEDIUM_TRACK_LEADOUT;
+
+	/* we fabricate the leadout here. We don't really need one in
+	 * fact since it is always at the last sector whatever the
+	 * amount of data written. So we need in fact to read the file
+	 * system and get the last sector from it. Hopefully it won't be
+	 * buggy */
+	priv->next_wr_add = 0;
+
+	leadout->blocks_num = priv->block_num;
+	if (g_slist_length (priv->tracks) > 1) {
+		BraseroMediumTrack *track;
+
+		track = priv->tracks->data;
+		leadout->blocks_num -= ((track->blocks_num > 300) ? track->blocks_num : 300);
+	}
+	BRASERO_BURN_LOG ("Adding fabricated leadout start = %llu length = %llu",
+			  leadout->start,
+			  leadout->blocks_num);
+}
+
+static BraseroBurnResult
+brasero_medium_get_sessions_info (BraseroMedium *self,
+				  BRASEROCDROM *cdrom)
+{
+	int num, i, size, res;
+	gint32 tstart;
+	unsigned char *toc = NULL;
+	unsigned char *desc;
+	BraseroMediumPrivate *priv;
+
+	BRASERO_BURN_LOG ("Reading Toc");
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+	res = brasero_cdrom_read_toc_formatted (cdrom, 0, &toc);
+	if (res != 0) {
+		g_free (toc);
+
+		BRASERO_BURN_LOG ("READ TOC failed");
+		return BRASERO_BURN_ERR;
+	}
+
+	size = (toc[0] << 8 | toc[1]) - 2;
+
+	num = size / 8; /* Each track description is 8 bytes. */
+
+	BRASERO_BURN_LOG ("%i track(s) found", num);
+
+	for (desc = toc + 4, i = 0; i < num; i ++, desc += 8) {
+		BraseroMediumTrack *track;
+
+		if (desc[2] == BRASERO_SCSI_TRACK_LEADOUT_START)
+			break;
+
+		tstart = (desc[4] << 24 | desc[5] << 16 | desc[6] << 8 | desc[7]);
+
+		track = g_new0 (BraseroMediumTrack, 1);
+		priv->tracks = g_slist_prepend (priv->tracks, track);
+		track->start = tstart;
+
+		/* we shouldn't request info on a track if the disc is closed */
+		brasero_medium_track_get_info (self,
+					       track,
+					       g_slist_length (priv->tracks),
+					       cdrom);
+
+		if ((desc[1] & 15) & BRASERO_SCSI_TRACK_COPY)
+			track->type |= BRASERO_MEDIUM_TRACK_COPY;
+
+		if (!((desc[1] & 15) & BRASERO_SCSI_TRACK_DATA)) {
+			track->type |= BRASERO_MEDIUM_TRACK_AUDIO;
+			priv->info |= BRASERO_MEDIUM_HAS_AUDIO;
+
+			if ((desc[1] & 15) & BRASERO_SCSI_TRACK_PREEMP)
+				track->type |= BRASERO_MEDIUM_TRACK_PREEMP;
+
+			if ((desc[1] & 15) & BRASERO_SCSI_TRACK_4_CHANNELS)
+				track->type |= BRASERO_MEDIUM_TRACK_4_CHANNELS;
+		}
+		else if (BRASERO_MEDIUM_IS (priv->info, BRASERO_MEDIUM_DVDRW_PLUS)
+		     ||  BRASERO_MEDIUM_IS (priv->info, BRASERO_MEDIUM_DVDRW_RESTRICTED)) {
+			BraseroBurnResult result;
+
+			/* a special case for these two kinds of media (DVD+RW)
+			 * which have only one track: the first. */
+			result = brasero_medium_track_volume_size (self,
+								   track,
+								   cdrom);
+			if (result == BRASERO_BURN_OK) {
+				track->type |= BRASERO_MEDIUM_TRACK_DATA;
+				priv->info |= BRASERO_MEDIUM_HAS_DATA;
+
+				priv->next_wr_add = 0;
+
+				if ((desc[1] & 15) & BRASERO_SCSI_TRACK_DATA_INCREMENTAL)
+					track->type |= BRASERO_MEDIUM_TRACK_INCREMENTAL;
+			}
+			else {
+				priv->tracks = g_slist_remove (priv->tracks, track);
+				g_free (track);
+
+				priv->info |= BRASERO_MEDIUM_BLANK;
+				priv->info &= ~BRASERO_MEDIUM_CLOSED;
+			}
+		}
+		else {
+			track->type |= BRASERO_MEDIUM_TRACK_DATA;
+			priv->info |= BRASERO_MEDIUM_HAS_DATA;
+
+			if ((desc[1] & 15) & BRASERO_SCSI_TRACK_DATA_INCREMENTAL)
+				track->type |= BRASERO_MEDIUM_TRACK_INCREMENTAL;
+		}
+	}
+
+	/* put the tracks in the right order */
+	priv->tracks = g_slist_reverse (priv->tracks);
+	tstart = (desc[4] << 24 | desc[5] << 16 | desc[6] << 8 | desc[7]);
+
+	if (BRASERO_MEDIUM_IS (priv->info, BRASERO_MEDIUM_DVDRW_PLUS)
+	||  BRASERO_MEDIUM_IS (priv->info, BRASERO_MEDIUM_DVDRW_RESTRICTED))
+		brasero_medium_add_DVD_plus_RW_leadout (self, tstart);
+	else if (!(priv->info & BRASERO_MEDIUM_CLOSED)) {
+		BraseroMediumTrack *track;
+
+		/* we shouldn't request info on leadout if the disc is closed
+		 * (except for DVD+/- (restricted) RW (see above) */
+		track = g_new0 (BraseroMediumTrack, 1);
+		priv->tracks = g_slist_append (priv->tracks, track);
+		track->start = tstart;
+		track->type = BRASERO_MEDIUM_TRACK_LEADOUT;
+
+		brasero_medium_track_get_info (self,
+					       track,
+					       g_slist_length (priv->tracks),
+					       cdrom);
+	}
+
+	g_free (toc);
+
+	return BRASERO_BURN_OK;
+}
+
+static BraseroBurnResult
+brasero_medium_get_contents (BraseroMedium *self,
+			     BRASEROCDROM *cdrom)
+{
+	BraseroBurnResult result;
+	int res;
+	BraseroMediumPrivate *priv;
+	unsigned char buf[32];
+
+	BRASERO_BURN_LOG ("Retrieving media status");
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+
+	res = brasero_cdrom_read_disc_information_std (cdrom, buf);
+	if (res != 0) {
+		BRASERO_BURN_LOG ("READ DISC INFORMATION failed");
+		return BRASERO_BURN_ERR;
+	}
+
+	if (buf[2] & 16) /* Erasable */
+		priv->info |= BRASERO_MEDIUM_REWRITABLE;
+
+	if ((buf[2] & 3) == 0) { /* Empty disc */
+		BraseroMediumTrack *track;
+
+		BRASERO_BURN_LOG ("Empty media");
+
+		priv->info |= BRASERO_MEDIUM_BLANK;
+		priv->block_size = 2048;
+
+		if (BRASERO_MEDIUM_IS (priv->info, BRASERO_MEDIUM_DVDRW_PLUS)
+		||  BRASERO_MEDIUM_IS (priv->info, BRASERO_MEDIUM_DVDRW_RESTRICTED))
+			brasero_medium_add_DVD_plus_RW_leadout (self, 0);
+		else {
+			track = g_new0 (BraseroMediumTrack, 1);
+			track->start = 0;
+			track->type = BRASERO_MEDIUM_TRACK_LEADOUT;
+			priv->tracks = g_slist_prepend (priv->tracks, track);
+
+			brasero_medium_track_get_info (self,
+						       track,
+						       1,
+						       cdrom);
+		}
+		goto end;
+	}
+
+	if (buf[2] & 1) { /* Appendable */
+		priv->info |= BRASERO_MEDIUM_APPENDABLE;
+		BRASERO_BURN_LOG ("Appendable media");
+	}
+	else if (buf[2] & 2) { /* Complete */
+		priv->info |= BRASERO_MEDIUM_CLOSED;
+		BRASERO_BURN_LOG ("Closed media");
+	}
+
+	if (priv->info & BRASERO_MEDIUM_CD) {
+		result = brasero_medium_get_CD_sessions_info (self, cdrom);
+		if (result != BRASERO_BURN_OK)
+			result = brasero_medium_get_sessions_info (self, cdrom);
+	}
+	else
+		result = brasero_medium_get_sessions_info (self, cdrom);
+
+	if (result != BRASERO_BURN_OK)
+		goto end;
+
+end:
+
+	return BRASERO_BURN_OK;
+}
+
+static void
+brasero_medium_init_real (BraseroMedium *object, BRASEROCDROM *cdrom)
+{
+	gchar *name;
+	BraseroBurnResult result;
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (object);
+
+	name = nautilus_burn_drive_get_name_for_display (priv->drive);
+	BRASERO_BURN_LOG ("Initializing information for medium in %s", name);
+	g_free (name);
+
+	result = brasero_medium_get_medium_type (object, cdrom);
+	if (result != BRASERO_BURN_OK)
+		return;
+
+	brasero_medium_get_capacity_by_type (object, cdrom);
+
+	result = brasero_medium_get_contents (object, cdrom);
+	if (result != BRASERO_BURN_OK)
+		return;
+
+	/* assume that css feature is only for DVD-ROM which might be wrong but
+	 * some drives wrongly reports that css is enabled for blank DVD+R/W */
+	if (BRASERO_MEDIUM_IS (priv->info, (BRASERO_MEDIUM_DVD|BRASERO_MEDIUM_ROM)))
+		brasero_medium_get_css_feature (object, cdrom);
+
+	BRASERO_BURN_LOG_DISC_TYPE (priv->info, "media is ");
+}
+
+static void
+brasero_medium_try_open (BraseroMedium *self)
+{
+	const gchar *path;
+	BRASEROCDROM *cdrom;
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (self);
+	path = nautilus_burn_drive_get_device (priv->drive);
+
+	BRASERO_BURN_LOG ("Trying to create BRASERCDROM for device %s", path);
+	cdrom = brasero_cdrom_new (path);
+	if (cdrom == NULL) {
+		BRASERO_BURN_LOG ("Creation failed");
+		return;
+	}
+
+	BRASERO_BURN_LOG ("Creation succeeded");
+	brasero_medium_init_real (self, cdrom);
+	brasero_cdrom_free (cdrom);
+}
+
+static void
+brasero_medium_init (BraseroMedium *object)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (object);
+	priv->next_wr_add = -1;
+
+	/* we can't do anything here since properties haven't been set yet */
+}
+
+static void
+brasero_medium_finalize (GObject *object)
+{
+	BraseroMediumPrivate *priv;
+
+	priv = BRASERO_MEDIUM_PRIVATE (object);
+
+	if (priv->retry_id) {
+		g_source_remove (priv->retry_id);
+		priv->retry_id = 0;
+	}
+
+	g_free (priv->rd_speeds);
+	priv->rd_speeds = NULL;
+
+	g_free (priv->wr_speeds);
+	priv->wr_speeds = NULL;
+
+	g_slist_foreach (priv->tracks, (GFunc) g_free, NULL);
+	g_slist_free (priv->tracks);
+	priv->tracks = NULL;
+
+	nautilus_burn_drive_unref (priv->drive);
+	priv->drive = NULL;
+
+	G_OBJECT_CLASS (parent_class)->finalize (object);
+}
+
+static void
+brasero_medium_set_property (GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
+{
+	BraseroMediumPrivate *priv;
+
+	g_return_if_fail (BRASERO_IS_MEDIUM (object));
+
+	priv = BRASERO_MEDIUM_PRIVATE (object);
+
+	switch (prop_id)
+	{
+	case PROP_DRIVE:
+		priv->drive = g_value_get_object (value);
+		nautilus_burn_drive_ref (priv->drive);
+		brasero_medium_try_open (BRASERO_MEDIUM (object));
+		break;
+	default:
+		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
+		break;
+	}
+}
+
+static void
+brasero_medium_get_property (GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
+{
+	BraseroMediumPrivate *priv;
+
+	g_return_if_fail (BRASERO_IS_MEDIUM (object));
+
+	priv = BRASERO_MEDIUM_PRIVATE (object);
+
+	switch (prop_id)
+	{
+	case PROP_DRIVE:
+		nautilus_burn_drive_ref (priv->drive);
+		g_value_set_object (value, priv->drive);
+		break;
+	default:
+		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
+		break;
+	}
+}
+
+static void
+brasero_medium_class_init (BraseroMediumClass *klass)
+{
+	GObjectClass* object_class = G_OBJECT_CLASS (klass);
+	parent_class = G_OBJECT_CLASS (g_type_class_peek_parent (klass));
+
+	g_type_class_add_private (klass, sizeof (BraseroMediumPrivate));
+
+	object_class->finalize = brasero_medium_finalize;
+	object_class->set_property = brasero_medium_set_property;
+	object_class->get_property = brasero_medium_get_property;
+
+	g_object_class_install_property (object_class,
+	                                 PROP_DRIVE,
+	                                 g_param_spec_object ("drive",
+	                                                      "drive",
+	                                                      "drive in which medium is inserted",
+	                                                      NAUTILUS_BURN_TYPE_DRIVE,
+	                                                      G_PARAM_READWRITE | G_PARAM_CONSTRUCT_ONLY));
+}
+
+GType
+brasero_medium_get_type (void)
+{
+	static GType our_type = 0;
+
+	if (our_type == 0)
+	{
+		static const GTypeInfo our_info =
+		{
+			sizeof (BraseroMediumClass), /* class_size */
+			(GBaseInitFunc) NULL, /* base_init */
+			(GBaseFinalizeFunc) NULL, /* base_finalize */
+			(GClassInitFunc) brasero_medium_class_init, /* class_init */
+			(GClassFinalizeFunc) NULL, /* class_finalize */
+			NULL /* class_data */,
+			sizeof (BraseroMedium), /* instance_size */
+			0, /* n_preallocs */
+			(GInstanceInitFunc) brasero_medium_init, /* instance_init */
+			NULL /* value_table */
+		};
+
+		our_type = g_type_register_static (G_TYPE_OBJECT, "BraseroMedium",
+		                                   &our_info, 0);
+	}
+
+	return our_type;
+}
+
+BraseroMedium *
+brasero_medium_new (NautilusBurnDrive *drive)
+{
+	g_return_val_if_fail (drive != NULL, NULL);
+	return BRASERO_MEDIUM (g_object_new (BRASERO_TYPE_MEDIUM,
+					     "drive", drive,
+					     NULL));
+}
