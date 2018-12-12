# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gecko-mediaplayer
PORTVERSION=	1.0.9
PORTREVISION=	7
CATEGORIES=	www multimedia gnome
MASTER_SITES=	https://pkgs.rpmfusion.org/repo/pkgs/free/gecko-mediaplayer/gecko-mediaplayer-1.0.9.tar.gz/69b50ecbbbf34ca6d980a477345dbd40/ \
		LOCAL/tobik:npapi
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		libxul-npapi-headers-45.9.0${EXTRACT_SUFX}:npapi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia browser plugin for Gecko based browsers

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libnspr4.so:devel/nspr \
		libcurl.so:ftp/curl \
		libgmlib.so:multimedia/gmtk
RUN_DEPENDS=	gnome-mplayer:multimedia/gnome-mplayer

USES=		compiler:c++11-lang gettext gnome localbase pkgconfig webplugin:native
USE_GNOME=	glib20
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-schemas-install \
		--with-plugin_dir="${WEBPLUGIN_DIR}"
CONFIGURE_ENV=	GECKO_CFLAGS="-I${WRKDIR}/npapi-headers -DHAVE_NSPR"

OPTIONS_DEFINE=		CACHE DOCS
OPTIONS_DEFAULT=	CACHE

CACHE_DESC=		Enable caching of remote media to local storage
CACHE_CONFIGURE_ENABLE=	caching

WEBPLUGIN_FILES=	${PORTNAME}.so
.for p in dvx rm qt wmp
WEBPLUGIN_FILES+=	${PORTNAME}-${p}.so
.endfor

post-patch:
	@${REINPLACE_CMD} -e \
		'/COPYING\\/d ; \
		 /INSTALL\\/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-ldl||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		"s|= (char) NULL;|= '\0';|" ${WRKSRC}/src/plugin_list.cpp

.include <bsd.port.mk>
