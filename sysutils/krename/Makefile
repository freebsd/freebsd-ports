# New ports collection makefile for:	krename
# Date created:				11 May 2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	krename
PORTVERSION=	3.0.14
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	SF/${PORTNAME}/KDE3%20${PORTNAME}-stable/${PORTVERSION}

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Very powerful batch file renamer for KDE3

USE_BZIP2=	yes
USE_KDELIBS_VER=3
USE_AUTOTOOLS=	libtool:22

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
