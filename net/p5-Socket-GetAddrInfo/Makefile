# New ports collection makefile for:	Socket::GetAddrInfo
# Date created:				29 November 2009
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	Socket-GetAddrInfo
PORTVERSION=	0.16
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sahil@FreeBSD.org
COMMENT=	RFC 2553's getaddrinfo and getnameinfo functions

BUILD_DEPENDS=	p5-ExtUtils-CChecker>=0.04:${PORTSDIR}/devel/p5-ExtUtils-CChecker

MAN3=		Socket::GetAddrInfo.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Module-Build>=0:${PORTSDIR}/devel/p5-Module-Build
.endif

.include <bsd.port.post.mk>
