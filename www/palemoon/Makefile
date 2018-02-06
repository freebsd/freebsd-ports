# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	palemoon
DISTVERSION=	27.7.2
DISTVERSIONSUFFIX=_Release
PORTREVISION=	1
CATEGORIES=	www ipv6

MAINTAINER=	lichray@gmail.com
COMMENT=	Open Source Goanna-based web browser

BUILD_DEPENDS=	nspr>=4.15:devel/nspr \
		nss>=3.31.1:security/nss \
		libevent>=2.0.22:devel/libevent \
		harfbuzz>=1.4.3:print/harfbuzz \
		graphite2>=1.3.10:graphics/graphite2 \
		png>=1.6.16:graphics/png \
		libvpx>=1.5.0:multimedia/libvpx \
		sqlite3>=3.19.3:databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		autoconf-2.13:devel/autoconf213 \
		yasm:devel/yasm \
		zip:archivers/zip

# Needs branding removed for legal reasons.
# Removing from our mirrors until this is handled.
# See PR 225717
LICENSE_PERMS=	no-pkg-mirror no-pkg-sell

USE_GITHUB=	yes
GH_ACCOUNT=	MoonchildProductions
GH_PROJECT=	Pale-Moon

USE_GECKO=	gecko
MOZ_PKGCONFIG_FILES=	# empty
USE_MOZILLA=	-soundtouch

USE_GL=		gl

PM_ICON=	${PORTNAME}.png
PM_ICON_SRC=	${PREFIX}/lib/${PORTNAME}/browser/icons/mozicon128.png
PM_DESKTOP=	${WRKSRC}/browser/branding/official/${PORTNAME}.desktop
MOZ_OPTIONS=	--enable-application=browser \
		--enable-official-branding \
		--enable-devtools \
		--enable-jemalloc \
		--enable-jemalloc-lib

OPTIONS_DEFAULT=	BUNDLED_CAIRO GTK2
OPTIONS_EXCLUDE=	DTRACE INTEGER_SAMPLES JACK TEST

.include "${.CURDIR}/../../www/firefox/Makefile.options"

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/browser/app/nsBrowserApp.cpp

pre-configure:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/autoconf-2.13)
	(cd ${WRKSRC}/js/src/ && ${LOCALBASE}/bin/autoconf-2.13)

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${PM_DESKTOP} ${STAGEDIR}${PREFIX}/share/applications/
	${LN} -sf ${PM_ICON_SRC} ${STAGEDIR}${PREFIX}/share/pixmaps/${PM_ICON}

.include <bsd.port.mk>
