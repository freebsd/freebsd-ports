# New ports collection makefile for:    nautilus
# Date created:         		28th August 2000
# Whom:                 		ade, archie
#
# $FreeBSD$
#

PORTNAME=	nautilus
PORTVERSION=	1.0.6
PORTREVISION=	9
CATEGORIES=	x11-fm gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/nautilus/1.0

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	medusa.0:${PORTSDIR}/sysutils/medusa \
		freetype.9:${PORTSDIR}/print/freetype2 \
		eel.0:${PORTSDIR}/x11-toolkits/eel
#RUN_DEPENDS=	${X11BASE}/share/gnome/ui/nautilus-galeon-view-ui.xml:${PORTSDIR}/www/galeon

.if defined(WITH_FAM) || exists(${LOCALBASE}/lib/libfam.so.0)
LIB_DEPENDS+=	fam.0:${PORTSDIR}/devel/fam
.endif

WITHOUT_MOZILLA=	"Doesn't work with Mozilla-0.9.9"

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
USE_GNOMENG=	yes
USE_GNOME=	gnomehack gnomeprefix gnomehier libpanel libghttp bonobo gnomevfs
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -fno-rtti -fno-exceptions" \
		LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz ${MOZILLA_LIBS}"
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

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
