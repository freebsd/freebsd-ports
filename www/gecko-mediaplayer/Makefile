# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	gecko-mediaplayer
PORTVERSION=	1.0.9
CATEGORIES=	www multimedia gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE:S,/files/,/svn/packages/,}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multimedia browser plugin for Gecko based browsers

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-glib-1.so:devel/dbus-glib \
		libnspr4.so:devel/nspr \
		libcurl.so:ftp/curl \
		libgmlib.so:multimedia/gmtk
RUN_DEPENDS=	gnome-mplayer:multimedia/gnome-mplayer

USES=		compiler:c++11-lang gecko gettext pkgconfig webplugin:native
USE_GNOME=	glib20
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--disable-schemas-install \
		--with-plugin_dir="${WEBPLUGIN_DIR}"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

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
		's|-std=c++11|| ; \
		 s|-ldl||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/COPYING\\/d ; \
		 /INSTALL\\/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-ldl||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		"s|= (char) NULL;|= '\0';|" ${WRKSRC}/src/plugin_list.cpp

.include <bsd.port.mk>
