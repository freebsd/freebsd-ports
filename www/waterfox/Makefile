# $FreeBSD$

PORTNAME=	waterfox
DISTVERSION=	56.0.2
CATEGORIES=	www ipv6

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Distilled fork of Firefox

DEPRECATED=	Temporary experiment
EXPIRATION_DATE=2018-01-30

BUILD_DEPENDS=	nspr>=4.16:devel/nspr \
		nss>=3.32.1:security/nss \
		icu>=59.1,1:devel/icu \
		libevent>=2.1.8:devel/libevent \
		harfbuzz>=1.4.7:print/harfbuzz \
		graphite2>=1.3.10:graphics/graphite2 \
		png>=1.6.31:graphics/png \
		libvorbis>=1.3.5,3:audio/libvorbis \
		libvpx>=1.5.0:multimedia/libvpx \
		sqlite3>=3.19.3:databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		v4l_compat>0:multimedia/v4l_compat \
		autoconf-2.13:devel/autoconf213 \
		yasm:devel/yasm \
		zip:archivers/zip
#		soundtouch>=1.9.0:audio/soundtouch \

LIB_DEPENDS=	libv4l2.so:multimedia/libv4l

USE_GITHUB=	yes
GH_ACCOUNT=	MrAlex94
GH_PROJECT=	Waterfox

USE_GECKO=	gecko
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	-soundtouch
MOZILLA_NAME=	Waterfox

USE_GL=		gl

WATERFOX_ICON=		${MOZILLA}.png
WATERFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/browser/chrome/icons/default/default256.png
WATERFOX_DESKTOP=	${MOZSRC}/taskcluster/docker/firefox-snap/firefox.desktop
MOZ_OPTIONS=	--enable-application=browser \
		--with-app-name=${MOZILLA} \
		--with-app-basename=${MOZILLA_NAME} \
		--with-distribution-id=org.${MOZILLA}project

OPTIONS_DEFAULT=	BUNDLED_CAIRO

.include "${.CURDIR}/../../www/firefox/Makefile.options"

post-patch:
	@${REINPLACE_CMD} -e 's/%u/%U/' -e '/X-MultipleArgs/d' \
		-e 's/firefox/${MOZILLA}/' \
		-e 's/Firefox/${MOZILLA_NAME}/' \
		${WATERFOX_DESKTOP}
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

post-install:
	${INSTALL_DATA} ${WATERFOX_DESKTOP} \
		${STAGEDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${LN} -sf ${WATERFOX_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${WATERFOX_ICON}

.include <bsd.port.mk>
