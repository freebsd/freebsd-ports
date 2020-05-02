# Created by: Alan Eldridge <alane@FreeBSD.org>
# $FreeBSD$

PORTNAME=	firefox
DISTVERSION=	76.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		MOZILLA/${PORTNAME}/candidates/${DISTVERSION}-candidates/build2/source
DISTFILES=	${DISTNAME}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

BUILD_DEPENDS=	nspr>=4.25:devel/nspr \
		nss>=3.51.1:security/nss \
		icu>=64.1,1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=2.6.4:print/harfbuzz \
		graphite2>=1.3.14:graphics/graphite2 \
		png>=1.6.35:graphics/png \
		libvpx>=1.8.2:multimedia/libvpx \
		py${PYTHON3_DEFAULT:S/.//}-sqlite3>0:databases/py-sqlite3@py${PYTHON3_DEFAULT:S/.//} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf-2.13:devel/autoconf213 \
		nasm:devel/nasm \
		yasm:devel/yasm \
		zip:archivers/zip

USE_GECKO=	gecko
CONFLICTS_INSTALL=	firefox-esr
USE_MOZILLA=	-sqlite

USES=		tar:xz

FIREFOX_ICON=		${MOZILLA}.png
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default48.png
FIREFOX_DESKTOP=	${MOZSRC}/taskcluster/docker/${MOZILLA}-snap/${MOZILLA}.desktop
MOZ_OPTIONS=	--enable-application=browser \
		--enable-official-branding

.include "${.CURDIR}/../../www/firefox/Makefile.options"

post-patch:
	@${REINPLACE_CMD} -e 's/%u/%U/' -e '/X-MultipleArgs/d' \
		-e '/^Icon/s/=.*/=${FIREFOX_ICON:R}/' \
		${FIREFOX_DESKTOP}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

post-install:
	${INSTALL_DATA} ${FIREFOX_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${FIREFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${FIREFOX_ICON}

.include <bsd.port.mk>
