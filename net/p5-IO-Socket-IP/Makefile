# New ports collection makefile for:	p5-IO-Socket-IP
# Date created:		2011-10-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-IP
PORTVERSION=	0.07
CATEGORIES=	net ipv6 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A drop-in replacement for IO::Socket::INET supporting both IPv4 and IPv6

BUILD_DEPENDS=	p5-Socket-GetAddrInfo>=0.17:${PORTSDIR}/net/p5-Socket-GetAddrInfo
RUN_DEPENDS=	p5-Socket-GetAddrInfo>=0.17:${PORTSDIR}/net/p5-Socket-GetAddrInfo

PERL_CONFIGURE=	yes

MAN3=		IO::Socket::IP.3

.include <bsd.port.mk>
