# New ports collection makefile for:	p5-Net-Traceroute6
# Date created:				13 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	Net-Traceroute6
PORTVERSION=	0.03
PORTREVISION=	1
CATEGORIES=	net perl5 ipv6
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to parse traceroute6(8) output

BUILD_DEPENDS=	p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Net::Traceroute6.3

.include <bsd.port.mk>
