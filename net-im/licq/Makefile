# New ports collection makefile for:    licq
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman & Matt Heckaman
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	${LICQ_VER}
PORTREVISION=	2
CATEGORIES=	net-im
PKGNAMESUFFIX=	${SOCKS_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A popular ICQ-compatible plugin-based program

.if defined(WITH_SOCKS)
BUILD_DEPENDS=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
.endif

USE_ICONV=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
LICQ_PORT?=	net-im/licq

# workaround for installed autoconf/automake
CONFIGURE_ARGS+=--program-transform-name=s,y,y,
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}" CPPFLAGS="${CPPFLAGS}"
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib -liconv
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include

.if defined(WITH_SOCKS)
SOCKS_SUFFIX=	-socks
CONFIGURE_ARGS+=--enable-socks5
CONFIGURE_ARGS+=--with-socks5-inc=${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFLICTS?=	licq-base-1.*
.else
CONFLICTS?=	licq-base-socks-1.*
.endif

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl-inc=${OPENSSLINC}
CONFIGURE_ARGS+=--with-openssl-lib=${OPENSSLLIB}
.endif

.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

pre-configure:
	${REINPLACE_CMD} -e 's=/usr/share/licq=${PREFIX}/share/licq=' \
		${WRKSRC}/src/licq.conf.h
	@${ECHO_MSG} Ignoring existing libgnugetopt
	${REINPLACE_CMD} -e 's=getopt.h==' \
		-e 's=FLAGS -D_THREAD_SAFE=FLAGS ${PTHREAD_CFLAGS}=' \
		-e 's=FLAGS -pthread=FLAGS ${PTHREAD_CFLAGS}=' \
		-e "s=-lc_r=${PTHREAD_LIBS}=" \
		-e 's=-lc *$$LIBS=$$LIBS=' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/lib/licq
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/${LICQ_PORT}/Makefile.inc"

.include <bsd.port.post.mk>
