# Ports collection Makefile for:	epiphany
# Date created:				24 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/epiphany/Makefile,v 1.195 2009/03/30 03:15:21 marcus Exp $
#

PORTNAME=	epiphany
PORTVERSION=	2.26.3
PORTREVISION?=	1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	An extremely lightweight and simple web browser for GNOME 2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		notify.1:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes \
    		${LOCALBASE}/share/icons/HighContrastLargePrint/index.theme:${PORTSDIR}/x11-themes/gnome-themes

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop desktopfileutils
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS} ${EXTRA_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS} ${EXTRA_LIBS}"

GCONF_SCHEMAS=	epiphany-lockdown.schemas epiphany.schemas \
		epiphany-fonts.schemas epiphany-pango.schemas

PLIST_SUB+=	EPHY_VERSION="${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}"

MAN1=		epiphany.1

OPTIONS=	SPELL_CHECKER "Enable spell checking support" off

.if defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

USE_GECKO+=	firefox libxul
CONFIGURE_ARGS+=	--with-gecko=${GECKO} \
			--with-engine=mozilla \
			--with-gecko-home=${LOCALBASE}/lib/${GECKO}
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
CONFLICTS=	epiphany-webkit-[1-9]*
PLIST_SUB+=	GECKO=""
.if ${GECKO:Mlibxul}!=""
PLUGIN_SYMLINK=	19
CONFIGURE_ENV+=gecko_cv_xpcom_program_check="yes"
PLIST_SUB+=	GECKO19=""
.else
PLUGIN_SYMLINK=	18
PLIST_SUB+=	GECKO19="@comment "
.endif

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

.if defined(WITH_SPELL_CHECKER)
LIB_DEPENDS+=	enchant.1:${PORTSDIR}/textproc/enchant
CONFIGURE_ARGS+=--enable-spell-checker
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g ; \
	    	s|-ldl"$$|"|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/lib/mozilla/plugins"|/lib/browser_plugins/symlinks/gecko${PLUGIN_SYMLINK}"|' \
		${WRKSRC}/embed/mozilla/mozilla-embed-single.cpp
	@${REINPLACE_CMD} -e 's|@with_engine@|mozilla|' \
		${WRKSRC}/data/epiphany.pc.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/epiphany-fonts.schemas \
		${PREFIX}/etc/gconf/schemas
	@-update-desktop-database

.include <bsd.port.post.mk>
