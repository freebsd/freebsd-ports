/*
 * Copyright (C) 2006 Jean-Yves Lefort <jylefort@FreeBSD.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdlib.h>
#include <time.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif /* HAVE_CONFIG_H */

#include "smartctl-sensors-interface.h"
#include "sensors-applet.h"

/* be gentle */
#define POLL_INTERVAL			30

typedef struct
{
  time_t	last_poll;
  double	value;
} SensorInfo;

static GHashTable *sensors;

static gboolean
smartctl_sensors_interface_run (const char *command,
				const char *device,
				char **output)
{
  char *argv[4];
  GSpawnFlags flags = G_SPAWN_STDERR_TO_DEV_NULL;
  char *_output = NULL;
  int exit_status;

  g_return_val_if_fail(command != NULL, FALSE);
  g_return_val_if_fail(device != NULL, FALSE);

  argv[0] = SMARTCTL_HELPER;
  argv[1] = (char *) command;
  argv[2] = (char *) device;
  argv[3] = NULL;

  if (! output)
    flags |= G_SPAWN_STDOUT_TO_DEV_NULL;

  if (g_spawn_sync(NULL, argv, NULL, flags, NULL, NULL, output ? &_output : NULL, NULL, &exit_status, NULL))
    {
      if (exit_status == 0)
	{
	  if (output)
	    *output = _output;

	  return TRUE;
	}
      g_free(_output);
    }

  return FALSE;
}

static gboolean
smartctl_sensors_interface_get_temperature (const char *device, double *temp)
{
  char *output;
  char **lines;
  int i;
  gboolean status = FALSE;

  g_return_val_if_fail(device != NULL, FALSE);

  if (! smartctl_sensors_interface_run("attributes", device, &output))
    return FALSE;

  lines = g_strsplit(output, "\n", 0);
  g_free(output);

  for (i = 0; lines[i]; i++)
    if (g_str_has_prefix(lines[i], "194 Temperature_Celsius"))
      {
	char *p;

	p = strrchr(lines[i], ' ');
	if (p)
	  {
	    double _temp;
	    char *end;

	    _temp = strtod(p + 1, &end);
	    if (*end == 0)
	      {
		status = TRUE;
		if (temp)
		  *temp = _temp;
	      }
	  }

	break;
      }
  g_strfreev(lines);

  return status;
}

static void
smartctl_sensors_interface_disk_init (SensorsApplet *sensors_applet,
			    const char *disk,
			    int unit)
{
  char *device;

  g_return_if_fail(sensors_applet != NULL);
  g_return_if_fail(disk != NULL);

  device = g_strdup_printf("/dev/%s%i", disk, unit);
  if (g_file_test(device, G_FILE_TEST_EXISTS)
      && smartctl_sensors_interface_run("enable", device, NULL)
      && smartctl_sensors_interface_get_temperature(device, NULL))
    {
      char *path;
      char *label;

      path = g_strdup_printf("/smartctl%s", device);
      label = g_strdup_printf("%s%i", disk, unit);

      sensors_applet_add_sensor(sensors_applet,
				path,
				device,
				label,
				SMARTCTL,
				TRUE,
				TEMP_SENSOR,
				HDD_ICON);

      g_free(path);
      g_free(label);
    }
  g_free(device);
}

void
smartctl_sensors_interface_init (SensorsApplet *sensors_applet)
{
  int i;

  sensors = g_hash_table_new(g_str_hash, g_str_equal);

  sensors_applet_register_sensors_interface(sensors_applet,
					    SMARTCTL,
					    smartctl_sensors_interface_get_sensor_value);

  /* smartctl supports ad(4) and da(4) disks */
  for (i = 0; i < 10; i++)
    {
      smartctl_sensors_interface_disk_init(sensors_applet, "ad", i);
      smartctl_sensors_interface_disk_init(sensors_applet, "da", i);
    }
}

double
smartctl_sensors_interface_get_sensor_value (const gchar *path, 
					     const gchar *id, 
					     SensorType type,
					     GError **error)
{
  SensorInfo *info;
  time_t now;

  info = g_hash_table_lookup(sensors, id);
  if (! info)
    {
      info = g_new0(SensorInfo, 1);
      g_hash_table_insert(sensors, g_strdup(id), info);
    }

  now = time(NULL);
  if (now == -1 || now - info->last_poll >= POLL_INTERVAL)
    {
      info->last_poll = now;
      smartctl_sensors_interface_get_temperature(id, &info->value);
    }

  return info->value;
}
