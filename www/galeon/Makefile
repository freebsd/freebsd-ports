# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	galeon
PORTVERSION=	1.2.13
PORTREVISION=	2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME Web browser based on gecko (the Mozilla rendering engine)

BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}

MOZ_CONFIGURE_ARGS=--with-mozilla-snapshot="trunk"

.if !defined(WITH_MOZILLA)
MOZILLA=	mozilla
HEADERS_SUFX=
.else
.if ${WITH_MOZILLA}=="mozilla-devel"
MOZILLA=	${WITH_MOZILLA}
HEADERS_SUFX=	-devel
MOZ_CONFIGURE_ARGS=	--with-mozilla-snapshot="1.6b"
.else
MOZILLA=	mozilla
HEADERS_SUFX=
.endif
.endif

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack bonobo libglade gnomevfs gnometarget
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-mozilla-includes="${X11BASE}/include/mozilla${HEADERS_SUFX}" \
		--with-mozilla-libs="${X11BASE}/lib/${MOZILLA}" \
		${MOZ_CONFIGURE_ARGS}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=		galeon.1

FLASHPLAYER=	${LOCALBASE}/lib/libflashplayer.so.1

CONFLICTS=	galeon2-*

.include <bsd.port.pre.mk>

NO_WERROR=	yes
# allow build with more warnings enabled
.if defined(NO_WERROR)
CONFIGURE_ARGS+=	--disable-werror
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default the port uses www/mozilla for html rendering, but you can change"
	@${ECHO_MSG} " this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla-devel "
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|' \
			  -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
			  ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "*.cpp" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${MKDIR} ${WRKSRC}/src/libnautilus

post-configure:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
			 s|%%LOCALBASE%%|${LOCALBASE}|g ; \
			 s|%%X11BASE%%|${X11BASE}|g ; \
			 s|%%FLASHPLAYER%%|${FLASHPLAYER}|g ; \
			 s|%%MOZILLA%%|${MOZILLA}|g' ${WRKSRC}/src/galeon \
						     ${WRKSRC}/src/nautstub.c

pre-install:
	@-${X11BASE}/bin/gconftool --shutdown

.include <bsd.port.post.mk>
