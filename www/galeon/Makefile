# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	galeon
PORTVERSION=	1.2.6
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/mozilla${HEADERS_SUFX}/gtkembedmoz/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers${HEADERS_SUFX} \
		${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}

WITH_FULL_MOZILLA=	"Problems with SSL, general performance, and usability"

.if defined(WITH_MOZILLA_DEVEL)
HEADERS_SUFX=	-devel
.if !defined(WITH_FULL_MOZILLA)
MOZILLA=	mozilla-embedded-devel
.else
MOZILLA=	mozilla-devel
.endif
.else
HEADERS_SUFX=
.if !defined(WITH_FULL_MOZILLA)
MOZILLA=	mozilla-embedded
.else
MOZILLA=	mozilla
.endif
.endif

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack bonobo libglade gnomevfs
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes="${X11BASE}/include/mozilla${HEADERS_SUFX}" \
		--with-mozilla-libs="${X11BASE}/lib/${MOZILLA}" \
		--enable-nautilus-view
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include -D_REENTRANT ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.if !defined(WITH_MOZILLA_DEVEL)
CONFIGURE_ARGS+=	--with-mozilla-snapshot="1.0"
.endif

MAN1=		galeon.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
# Galeon does not build correctly in -CURRENT if -Werror is passed
# to the compiler.
CONFIGURE_ARGS+=	--disable-werror
.endif

post-extract:
.if !defined(WITH_FULL_MOZILLA)
	@${ECHO_MSG}
	@${ECHO_MSG} " By default the port uses mozilla-embedded for html rendering, but if you are"
	@${ECHO_MSG} " planning to use both Mozilla and Galeon you can instruct it to use mozilla by"
	@${ECHO_MSG} " defining \"WITH_FULL_MOZILLA\"."
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${FIND} ${WRKSRC} -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${MKDIR} ${WRKSRC}/src/libnautilus

post-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
			 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			 s|%%X11BASE%%|${X11BASE}|g ; \
			 s|%%MOZILLA%%|${MOZILLA}|g' ${WRKSRC}/src/galeon \
						     ${WRKSRC}/src/nautstub.c

pre-install:
	@-${X11BASE}/bin/gconftool --shutdown

.include <bsd.port.post.mk>
