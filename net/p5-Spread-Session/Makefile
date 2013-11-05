# Created by: Joshua Goodall <joshua@roughtrade.net>
# $FreeBSD$

PORTNAME=	Spread-Session
PORTVERSION=	0.4
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JMAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl OO wrapper for Spread messaging toolkit

BUILD_DEPENDS=	spread>=0:${PORTSDIR}/net/spread
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
