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

MAINTAINER=	dinoex@FreeBSD.org

.if defined(WITH_SOCKS)
BUILD_DEPENDS=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
.endif

USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
.if defined(WITH_SOCKS)
CONFIGURE_ARGS+=--enable-socks5
.endif

post-patch:
	@${PERL5} -pi -e 's|<wait.h>|<sys/wait.h>|g' \
		${WRKSRC}/src/sighandler.c
	@${PERL5} -pi -e 's|.program_transform_name.|s,x,x,|' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/Makefile.inc"
.include <bsd.port.mk>
