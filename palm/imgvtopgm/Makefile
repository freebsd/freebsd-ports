# New ports collection makefile for:    imgvtopgm
# Date created:         Wed Jun 16 04:42:22 JST 1999
# Whom:                 sumikawa@ebina.hitachi.co.jp
#
# $FreeBSD$
#

PORTNAME=	imgvtopgm
PORTVERSION=	2.0
CATEGORIES=	palm graphics
MASTER_SITES=	http://www.linuxmafia.com/pub/palmos/other-os/

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Palm Pilot Image Viewer to PGM Converter

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm

GNU_CONFIGURE=	yes
CONFIGUR_ARGS=	--libdir=${PREFIX}

MAN1=		imgvinfo.1 imgvtopnm.1 imgvview.1 pbmtoimgv.1 \
		pgmtoimgv.1 ppmimgvquant.1

.include <bsd.port.mk>
