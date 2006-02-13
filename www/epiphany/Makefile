# Ports collection Makefile for:	epiphany
# Date created:				24 April 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/epiphany/Makefile,v 1.84 2005/10/02 23:28:19 marcus Exp $
#

PORTNAME=	epiphany
PORTVERSION=	1.8.5
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.8
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An extremely lightweight and simple web browser for GNOME 2

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USE_BZIP2=	yes
USE_X_PREFIX=	yes
GNOME_DESKTOP_VERSION=2
USE_GECKO=	firefox mozilla seamonkey
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop desktopfileutils \
		libgnomeprintui
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_OMF=	yes
CONFIGURE_ARGS=	--with-mozilla=${GECKO} \
		--disable-python
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

GCONF_SCHEMAS=	epiphany-lockdown.schemas epiphany.schemas

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1
PLIST_SUB+=	EPHY_VERSION="1.8"

MAN1=		epiphany.1

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../www/mozilla/bsd.gecko.mk"

.if ${OSVERSION} < 500000
IGNORE=	does not build on 4.X
.endif

NO_WERROR=	yes
# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--enable-compile-warnings=no
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${REINPLACE_CMD} -e 's|execinfo.h|#|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/lib/mozilla/plugins|/lib/browser_plugins:${X11BASE}/lib/browser_linux_plugins|' \
		${WRKSRC}/embed/mozilla/mozilla-embed-single.cpp

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
