# New ports collection makefile for:    licq
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman & Matt Heckaman
#
# $FreeBSD$
#

PORTNAME=	base
PORTVERSION=	${LICQ_VER}
CATEGORIES=	net
.if defined(WITH_SOCKS)
PKGNAMESUFFIX=	-socks
.endif

MAINTAINER=	fjoe@FreeBSD.org

.if defined(WITH_SOCKS)
.if defined(WITH_DANTE)
LIB_DEPENDS=	socks.1:${PORTSDIR}/net/dante
.else
BUILD_DEPENDS=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
.endif
.endif

USE_OPENSSL=	yes
.if defined(USE_CVS)
WRKSRC=		${WRKDIR}/licq
CVS_MODULE=	licq
.else
WRKSRC=		${WRKDIR}/licq-${TIMESTAMP}
.endif
.if defined(WITH_SOCKS)
CONFIGURE_ARGS+=--enable-socks5
.if defined(WITH_DANTE)
CONFIGURE_ARGS+=--with-socks5-inc=${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS=-L${LOCALBASE}/lib
.endif
.endif

post-patch:
	@${PERL5} -pi -e 's|<wait.h>|<sys/wait.h>|g' \
		${WRKSRC}/src/sighandler.c
	@${PERL5} -pi -e 's|.program_transform_name.|s,x,x,|' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/Makefile.inc"
.include <bsd.port.post.mk>
