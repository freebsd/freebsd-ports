# New ports collection makefile for:   sg3_utils
# Date created:        06 Jun 2008
# Whom:                Denis Barov <dindin@dindin.ru>
#
# $FreeBSD$
#

PORTNAME=	sg3_utils
PORTVERSION=	1.28
CATEGORIES=	sysutils
MASTER_SITES=	http://sg.danny.cz/sg/p/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of utilities that send SCSI commands to devices

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAN8=		scsi_readcap.8 scsi_ready.8 scsi_start.8 scsi_stop.8 \
		sg3_utils.8 sg_format.8 sg_get_config.8 sg_get_lba_status.8 \
		sg_ident.8 sg_inq.8 sg_logs.8 sg_luns.8 sg_modes.8 \
		sg_opcodes.8 sg_persist.8 sg_prevent.8 sg_raw.8 sg_rdac.8 \
		sg_read_block_limits.8 sg_read_buffer.8 sg_read_long.8 \
		sg_readcap.8 sg_reassign.8 sg_requests.8 sg_rmsn.8 \
		sg_rtpg.8 sg_safte.8 sg_sat_identify.8 sg_sat_phy_event.8 \
		sg_sat_set_features.8 sg_senddiag.8 sg_ses.8 sg_start.8 \
		sg_stpg.8 sg_sync.8 sg_turs.8 sg_unmap.8 sg_verify.8 \
		sg_vpd.8 sg_wr_mode.8 sg_write_buffer.8 sg_write_long.8 \
		sg_write_same.8

.include <bsd.port.mk>
