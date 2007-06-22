# New ports collection makefile for: mugshot
# Date Created:                      24 December 2006
# Whom:                              wahjava
#
# $FreeBSD$
#

PORTNAME=	mugshot
PORTVERSION=	1.1.45
CATEGORIES=	net
MASTER_SITES=	http://download.mugshot.org/client/sources/linux/

MAINTAINER=	wahjava@gmail.com
COMMENT=	The official client for Mugshot network

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg:install \
		Xss.1:${PORTSDIR}/x11/xorg-libraries:install
BUILD_DEPENDS=	${PKGCONFIG_LOCAL_BASE}/dbus-1.pc:${PORTSDIR}/devel/dbus:install \
		${PKGCONFIG_LOCAL_BASE}/dbus-glib-1.pc:${PORTSDIR}/devel/dbus-glib:install \
		${PKGCONFIG_LOCAL_BASE}/loudmouth-1.0.pc:${PORTSDIR}/net-im/loudmouth:install \
		${PKGCONFIG_LOCAL_BASE}/cairo.pc:${PORTSDIR}/graphics/cairo:install \
		${PKGCONFIG_LOCAL_BASE}/libcurl.pc:${PORTSDIR}/ftp/curl:install \
		${LOCALBASE}/include/firefox/caps/nsIScriptSecurityManager.h:${PORTSDIR}/www/firefox:install \
		${LOCALBASE}/lib/libpcre.a:${PORTSDIR}/devel/pcre:install \
		${LOCALBASE}/lib/firefox/xpidl:${PORTSDIR}/www/firefox:install \
		${X11BASE}/include/X11/extensions/scrnsaver.h:${PORTSDIR}/x11/xorg-libraries:install \
		dbus>=1.0.2:${PORTSDIR}/devel/dbus:install

USE_GNOME=	gnomehack gconf2 glib20 gtk20 pango gnomevfs2 gnomedesktop
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

GCONF_SCHEMAS=	mugshot-uri-handler.schemas
INSTALLS_ICONS=	yes

USE_LDCONFIG=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/mugshot/firefox/components

PKGCONFIG_LOCAL_BASE=	${LOCALBASE}/libdata/pkgconfig
PKGCONFIG_X11_BASE=	${X11BASE}/libdata/pkgconfig

mugshot_INSTALL_cmd=	install

.include <bsd.port.pre.mk>

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	"--with-gecko-idl=${FIREFOX_IDL_PATH}" \
		"--with-gecko-headers=${LOCALBASE}/include/firefox" \
		"--with-xpidl=${LOCALBASE}/lib/firefox/xpidl" \
		"--x-includes=${X11BASE}/include" \
		"--x-libraries=${X11BASE}/lib"

FIREFOX_IDL_PATH!=${SH} -c 'for i in ${LOCALBASE}/share/idl/firefox-*; do [ -f $$i/nsIURI.idl ] && ${ECHO} $$i && break; done; exit 0;'
BUILD_DEPENDS+=${FIREFOX_IDL_PATH}/nsIURI.idl:${PORTSDIR}/www/firefox:install

post-install:
	@${SED} -i "" -e "s|%%PREFIX%%|${PREFIX}|" ${PREFIX}/share/mugshot/firefox-update.sh
	@${PREFIX}/share/mugshot/firefox-update.sh ${mugshot_INSTALL_cmd}

.include <bsd.port.post.mk>
