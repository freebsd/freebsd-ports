# New ports collection makefile for:	p5-IO-Socket-IP
# Date created:		2011-10-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-IP
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	net ipv6 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A drop-in replacement for IO::Socket::INET supporting IPv4 and IPv6

PERL_CONFIGURE=	yes

MAN3=		IO::Socket::IP.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Socket-GetAddrInfo>=0.17:${PORTSDIR}/net/p5-Socket-GetAddrInfo
RUN_DEPENDS+=	p5-Socket-GetAddrInfo>=0.17:${PORTSDIR}/net/p5-Socket-GetAddrInfo
.endif

.include <bsd.port.post.mk>
