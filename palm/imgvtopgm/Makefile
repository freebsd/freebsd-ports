# Created by: sumikawa@ebina.hitachi.co.jp
# $FreeBSD$

PORTNAME=	imgvtopgm
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	palm graphics
MASTER_SITES=	http://linuxmafia.com/pub/palmos/other-os/

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Palm Pilot Image Viewer to PGM Converter

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm

GNU_CONFIGURE=	yes
CONFIGUR_ARGS=	--libdir=${PREFIX}

MAN1=		imgvinfo.1 imgvtopnm.1 imgvview.1 pbmtoimgv.1 \
		pgmtoimgv.1 ppmimgvquant.1

NO_STAGE=	yes
.include <bsd.port.mk>
