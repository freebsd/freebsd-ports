# New ports collection makefile for:    nautilus
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#

PORTNAME=	nautilus
PORTVERSION=	0.8
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	unstable/sources/nautilus

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	rpm:${PORTSDIR}/archivers/rpm \
		freetype-config:${PORTSDIR}/print/freetype2	# XXX
LIB_DEPENDS=	medusa.0:${PORTSDIR}/sysutils/medusa \
		gtkhtml.8:${PORTSDIR}/www/gtkhtml \
		ghttp.1:${PORTSDIR}/www/libghttp \
		bz2.1:${PORTSDIR}/archivers/bzip2 \
		freetype.6:${PORTSDIR}/print/freetype2

.if defined(WITH_MOZILLA)
MOZILLA=	mozilla
BUILD_DEPENDS=	${X11BASE}/include/mozilla/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers \
		${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
.endif

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -fno-rtti -fno-exceptions" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz ${MOZILLA_LIBS}"
CONFIGURE_ARGS=	--with-freetype2-lib-place=${LOCALBASE}/lib \
		--with-freetype2-include-place=${LOCALBASE}/include/freetype2

.if defined(WITH_MOZILLA)
CONFIGURE_ARGS+= --with-mozilla-lib-place=${X11BASE}/lib/${MOZILLA} \
		 --with-mozilla-include-place=${X11BASE}/include/mozilla
MOZILLA_LIBS=	"-L${X11BASE}/lib/${MOZILLA}"
PLIST_SUB+=	MOZILLA:=""
.else
CONFIGURE_ARGS+= --disable-mozilla-component
MOZILLA_LIBS=	""
PLIST_SUB+=	MOZILLA:="@comment "
.endif

.if !defined(WITH_MOZILLA)
pre-extract:
	@${ECHO} "You can add embedded mozilla support by defining WITH_MOZILLA"
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
