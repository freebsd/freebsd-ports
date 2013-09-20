# Created by: Stefan Eßer <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kplayer
PORTVERSION=	0.7
PORTREVISION=	3
CATEGORIES=	multimedia kde
MASTER_SITES=	SF

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Movie player based on mplayer

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USES=		cmake gettext
USE_QT4=	corelib qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix kdelibs automoc4

NO_STAGE=	yes
post-patch:
.for lang in da en es it pt sv
	${REINPLACE_CMD} -e "s,HTML_INSTALL_DIR},HTML_INSTALL_DIR}/${lang} SUBDIR kplayer,g" \
	 ${WRKSRC}/doc/${lang}/CMakeLists.txt
.endfor
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc/*/index.docbook

.include <bsd.port.mk>
