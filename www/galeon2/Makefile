# Ports collection Makefile for:	galeon2
# Date created:				16 November 2002
# Whom:					Maxime Romano <verbophobe@jewcrew.org>
#
# $FreeBSD$
#

PORTNAME=	galeon2
PORTVERSION=	1.3.1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/2$//}
DISTNAME=	${PORTNAME:S/2$//}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/include/mozilla${HEADERS_SUFX}/gtkembedmoz/gtkmozembed.h:${PORTSDIR}/www/mozilla-headers${HEADERS_SUFX} \
		${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}
LIB_DEPENDS=	gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/components/libwidget_gtk2.so:${PORTSDIR}/www/${MOZILLA}

MOZ_CONFIGURE_ARGS=	--with-mozilla-snapshot="1.2"

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla-gtk2
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel-gtk2"
MOZILLA=	${WITH_MOZILLA}
HEADERS_SUFX=	-devel
MOZ_CONFIGURE_ARGS=	--with-mozilla-snapshot="trunk"
.else
MOZILLA=	mozilla
HEADERS_SUFX=
.endif
.endif

USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes="${X11BASE}/include/mozilla${HEADERS_SUFX}" \
		--with-mozilla-libs="${X11BASE}/lib/${MOZILLA}" \
		--enable-nautilus-view=no \
		${MOZ_CONFIGURE_ARGS}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include -D_REENTRANT ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		galeon.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
# Galeon does not build correctly in -CURRENT if -Werror is passed
# to the compiler.
CONFIGURE_ARGS+=	--enable-werror
.endif

post-extract:
	@${ECHO_MSG}
	@${ECHO_MSG} " By default the port uses www/mozilla-gtk2 for html rendering, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla-devel-gtk2 "
	@${ECHO_MSG}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in*" | xargs ${REINPLACE_CMD} -e \
		 's|-lpthread|${PTHREAD_LIBS}|g'
	@${FIND} ${WRKSRC} -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'

post-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%X11BASE%%|${X11BASE}|g ; \
		s|%%MOZILLA%%|${MOZILLA}|g' ${WRKSRC}/src/galeon

pre-install:
	@-${X11BASE}/bin/gconftool --shutdown

.include <bsd.port.post.mk>
