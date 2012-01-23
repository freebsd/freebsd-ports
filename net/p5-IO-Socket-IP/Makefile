# New ports collection makefile for:	p5-IO-Socket-IP
# Date created:		2011-10-15
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-IP
PORTVERSION=	0.08
CATEGORIES=	net ipv6 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	A drop-in replacement for IO::Socket::INET supporting IPv4 and IPv6

BUILD_DEPENDS=	p5-Socket>=1.95:${PORTSDIR}/net/p5-Socket
RUN_DEPENDS=	p5-Socket>=1.95:${PORTSDIR}/net/p5-Socket

TEST_DEPENDS=	p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

PERL_CONFIGURE=	yes

MAN3=		IO::Socket::IP.3

.include <bsd.port.mk>
