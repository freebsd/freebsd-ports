# New ports collection makefile for:	kplayer
# Date created:				Fri Apr 11 09:12:55 CEST 2003
# Whom:					Stefan Eßer <se@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kplayer
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	multimedia kde
MASTER_SITES=	SF

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Movie player based on mplayer

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix kdelibs automoc4
MAKE_JOBS_SAFE=	yes

post-patch:
.for lang in da en es it pt sv
	${REINPLACE_CMD} -e "s,HTML_INSTALL_DIR},HTML_INSTALL_DIR}/${lang} SUBDIR kplayer,g" \
	 ${WRKSRC}/doc/${lang}/CMakeLists.txt
.endfor
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc/*/index.docbook

.include <bsd.port.mk>
