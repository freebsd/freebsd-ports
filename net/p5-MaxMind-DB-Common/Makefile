# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MaxMind-DB-Common
PORTVERSION=	0.031.002
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DROLSKY
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Code shared by the DB reader and writer modules

LICENSE=	ART20

BUILD_DEPENDS=	p5-Data-Dumper-Concise>=0:${PORTSDIR}/devel/p5-Data-Dumper-Concise \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-List-AllUtils>=0:${PORTSDIR}/devel/p5-List-AllUtils \
		p5-Math-Int128>=0:${PORTSDIR}/math/p5-Math-Int128 \
		p5-Moo>=0:${PORTSDIR}/devel/p5-Moo \
		p5-MooX-StrictConstructor>=0:${PORTSDIR}/devel/p5-MooX-StrictConstructor \
		p5-autodie>=0:${PORTSDIR}/devel/p5-autodie \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
