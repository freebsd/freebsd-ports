# Ports collection Makefile for:	epiphany
# Date created:				24 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/epiphany/Makefile,v 1.141 2007/03/11 20:12:27 mezz Exp $
#

PORTNAME=	epiphany
PORTVERSION=	2.18.3
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An extremely lightweight and simple web browser for GNOME 2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_XLIB=	yes
USE_PYTHON=	yes
GNOME_DESKTOP_VERSION=2
USE_GECKO=	firefox seamonkey firefox15<->firefox xulrunner
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop desktopfileutils
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--with-mozilla=${GECKO} --mandir=${MANPREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

GCONF_SCHEMAS=	epiphany-lockdown.schemas epiphany.schemas \
		epiphany-fonts.schemas epiphany-pango.schemas

PLIST_SUB+=	EPHY_VERSION="${PORTVERSION:C/\.[0-9]+$//}" \
		EPHY_PREFIX="${PREFIX}"

MAN1=		epiphany.1

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
#.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

NO_WERROR=	yes
# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--enable-compile-warnings=no
.endif

.if ${HAVE_GNOME:Mpygnome2}!=""
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
USE_GNOME+=	pygnome2
CONFIGURE_ARGS+=--enable-python
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/lib/mozilla/plugins"|/lib/browser_plugins" ":" MOZILLA_PREFIX "/lib/browser_linux_plugins"|' \
		${WRKSRC}/embed/mozilla/mozilla-embed-single.cpp
	@${REINPLACE_CMD} -e 's|[$$](datadir)/pygtk/2.0/defs|${LOCALBASE}/share/pygtk/2.0/defs|' \
		${WRKSRC}/src/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/epiphany-fonts.schemas \
		${PREFIX}/etc/gconf/schemas
	@-update-desktop-database

.include <bsd.port.post.mk>
