# New ports collection makefile for:    licq
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman & Matt Heckaman
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	${LICQ_VER}
PORTREVISION=	1
CATEGORIES=	net
.if defined(WITH_SOCKS)
PKGNAMESUFFIX=	-socks
.endif

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A popular ICQ-compatible plugin-based program

.if defined(WITH_SOCKS)
BUILD_DEPENDS=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
.endif

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
LICQ_PORT?=	${.CURDIR}

# workaround for installed autoconf/automake
CONFIGURE_ARGS+=--program-transform-name=s,y,y,
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
LDFLAGS+=	${PTHREAD_LIBS}

.if defined(WITH_SOCKS)
CONFIGURE_ARGS+=--enable-socks5
CONFIGURE_ARGS+=--with-socks5-inc=${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-openssl-inc=${OPENSSLINC}
CONFIGURE_ARGS+=--with-openssl-lib=${OPENSSLLIB}
.endif

pre-configure:
	${REINPLACE_CMD} -e 's=/usr/share/licq=${PREFIX}/share/licq=' \
		${WRKSRC}/src/licq.conf.h
	@${ECHO_MSG} Ignoring existing libgnugetopt
	${REINPLACE_CMD} -e 's=getopt.h==' \
		-e 's=FLAGS -pthread=FLAGS ${PTHREAD_CFLAGS}=' \
		${WRKSRC}/configure

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include "${LICQ_PORT}/Makefile.inc"
.include <bsd.port.post.mk>
