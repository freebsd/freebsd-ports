# New ports collection makefile for:    nautilus
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#

PORTNAME=	nautilus
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/nautilus

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2 \
		msgfmt-new:${PORTSDIR}/devel/gettext-devel
LIB_DEPENDS=	medusa.0:${PORTSDIR}/sysutils/medusa \
		freetype.8:${PORTSDIR}/print/freetype2 \
		eel.0:${PORTSDIR}/x11-toolkits/eel

.if !defined(WITHOUT_MOZILLA)
.if !defined(WITH_FULL_MOZILLA)
MOZILLA=	mozilla-embedded
.else
MOZILLA=	mozilla
.endif
BUILD_DEPENDS+=	${X11BASE}/include/mozilla/gtkembedmoz/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers \
		${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
.endif

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -fno-rtti -fno-exceptions" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib -lgiconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz ${MOZILLA_LIBS}" \
		MSGFMT=${LOCALBASE}/bin/msgfmt-new \
                XGETTEXT=${LOCALBASE}/bin/xgettext-new
CONFIGURE_ARGS=	--with-freetype2-lib-place=${LOCALBASE}/lib \
		--with-freetype2-include-place=${LOCALBASE}/include/freetype2

.if !defined(WITHOUT_MOZILLA)
CONFIGURE_ARGS+= --with-mozilla-lib-place=${X11BASE}/lib/${MOZILLA} \
		 --with-mozilla-include-place=${X11BASE}/include/mozilla
MOZILLA_LIBS=	"-L${X11BASE}/lib/${MOZILLA}"
PLIST_SUB+=	MOZILLA:=""
.else
CONFIGURE_ARGS+= --disable-mozilla-component
MOZILLA_LIBS=	""
PLIST_SUB+=	MOZILLA:="@comment "
.endif

MAN1=		nautilus-xml-migrate.1

.if !defined(WITHOUT_MOZILLA)
pre-extract:
.if !defined(WITH_FULL_MOZILLA)
	@${ECHO_MSG}
	@${ECHO_MSG} " By default the port uses mozilla-embedded for html rendering, but if you are"
	@${ECHO_MSG} " planning to use both Mozilla and Nautilus you can instruct it to use mozilla by"
	@${ECHO_MSG} " defining \"WITH_FULL_MOZILLA\"."
	@${ECHO_MSG}
.endif
	@${ECHO_MSG} "You can remove embedded mozilla support by defining WITHOUT_MOZILLA."
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

.include <bsd.port.mk>
