# New ports collection makefile for:	kplayer
# Date created:				Fri Apr 11 09:12:55 CEST 2003
# Whom:					Stefan Eßer <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kplayer
PORTVERSION=	0.7
CATEGORIES=	multimedia kde
MASTER_SITES=	SF

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Movie player based on mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix kdelibs

post-extract:
.for lang in da en es it pt sv
	${REINPLACE_CMD} -e "s,HTML_INSTALL_DIR},HTML_INSTALL_DIR}/${lang} SUBDIR kplayer,g" \
	 ${WRKSRC}/doc/${lang}/CMakeLists.txt
.endfor

.include <bsd.port.mk>
