# Ports collection Makefile for:	epiphany
# Date created:				24 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/epiphany/Makefile,v 1.84 2005/10/02 23:28:19 marcus Exp $
#

PORTNAME=	epiphany
PORTVERSION=	1.8.2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.8
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An extremely lightweight and simple web browser for GNOME 2

BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA} \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA} \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

MOZILLA=	mozilla
HEADERS_SUFX=
MOZ_BUILD=	mozilla

.if !defined(WITH_MOZILLA)
MOZILLA=	firefox
HEADERS_SUFX=
MOZ_BUILD=	firefox
.else
.if ${WITH_MOZILLA}=="mozilla"
MOZILLA=	mozilla
MOZ_BUILD=	mozilla
.else
.if ${WITH_MOZILLA}=="mozilla-devel" || ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	mozilla-devel
HEADERS_SUFX=	-devel
.else
MOZILLA=	firefox
HEADERS_SUFX=
MOZ_BUILD=	firefox
.endif
.endif
.endif

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop desktopfileutils \
		libgnomeprintui
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--with-mozilla=${MOZ_BUILD} \
		--disable-python
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

GCONF_SCHEMAS=	epiphany-lockdown.schemas epiphany.schemas

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1
PLIST_SUB+=	EPHY_VERSION="${PORTVERSION:C/\.[0-9]+$//}"

MAN1=		epiphany.1

.include <bsd.port.pre.mk>

NO_WERROR=	yes
# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--enable-compile-warnings=no
.endif

.if ${OSVERSION} < 500000
.if ${MOZILLA}=="mozilla-devel"
USE_GCC=	3.4
.endif
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default epiphany uses www/firefox for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla       "
	@${ECHO_MSG} "  mozilla-devel "
	@${ECHO_MSG} ""

post-patch:
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA}=="mozilla-devel"
	@${REINPLACE_CMD} -e 's|xmozilla|xmozilla${HEADERS_SUFX}|g; \
		s|mozilla)|mozilla${HEADERS_SUFX})|g; \
		s|mozilla-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g; \
		s|mozilla-xpcom|mozilla-xpcom${HEADERS_SUFX}|g; \
		s|$$MOZILLA-gtkmozembed|mozilla-gtkmozembed${HEADERS_SUFX}|g; \
		s|$$MOZILLA-xpcom|mozilla-xpcom${HEADERS_SUFX}|g' \
		${WRKSRC}/configure
.endif
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
        @${REINPLACE_CMD} -e 's|execinfo.h|#|g' \
                ${WRKSRC}/configure

post-configure:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%MOZILLA%%|${MOZILLA}|g ; \
		s|%%FLASHPLAYER%%|${FLASHPLAYER}|g' <${FILESDIR}/epiphany \
		> ${WRKDIR}/epiphany

post-install:
	@${MV} -f ${PREFIX}/bin/epiphany ${PREFIX}/bin/epiphany-bin
	${INSTALL_SCRIPT} ${WRKDIR}/epiphany ${PREFIX}/bin
	@-update-desktop-database

.include <bsd.port.post.mk>
