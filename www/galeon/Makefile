# Ports collection Makefile for:	galeon
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	galeon
PORTVERSION=	1.2.14
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A GNOME Web browser based on gecko (the Mozilla rendering engine)

BUILD_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}
RUN_DEPENDS=	${X11BASE}/lib/${MOZILLA}/libgtkembedmoz.so:${PORTSDIR}/www/${MOZILLA}

MOZ_CONFIGURE_ARGS=--with-mozilla-snapshot="1.7"

MOZILLA=	mozilla-gtk1
HEADERS_SUFX=	-gtk1

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack bonobo libglade gnomevfs \
		gnometarget
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LIBTOOL_VER=13
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
