PORTNAME=	obs-qtwebkit
PORTVERSION=	g2018090201
PORTREVISION=	6
CATEGORIES=	multimedia

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Browser source plugin for obs-studio
WWW=		https://github.com/swills/obs-qtwebkit

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		OBS ships with their own browser plugin from version 25 onwards
EXPIRATION_DATE=	2023-06-16

LIB_DEPENDS=	libobs.so:multimedia/obs-studio \
		libinotify.so:devel/libinotify

USES=		compiler:c++11-lang gmake pkgconfig qt:5
USE_QT=		core gui network webkit widgets

USE_GITHUB=	yes
GH_ACCOUNT=	swills
GH_TAGNAME=	c01aa76
MAKEFILE=	GNUmakefile
MAKE_ARGS=	OBS_INCLUDE=${LOCALBASE}/include OBS_LIB=${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${WRKSRC}/GNUmakefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/obs-plugins/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/obs/obs-plugins/qtwebkit-browser/data/locale
	${INSTALL_PROGRAM} ${WRKSRC}/build/qtwebkit-browser.so ${STAGEDIR}${PREFIX}/lib/obs-plugins/
	${INSTALL_PROGRAM} ${WRKSRC}/build/renderer ${STAGEDIR}${PREFIX}/lib/obs-plugins/
	cd ${WRKSRC}/build/qtwebkit-browser/data/locale ; ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/obs/obs-plugins/qtwebkit-browser/data/locale

.include <bsd.port.mk>
