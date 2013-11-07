# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	Catalyst-Model-DynamicAdaptor
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	www devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOMYHERO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dynamically load adaptor modules

BUILD_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Module-Recursive-Require>=0:${PORTSDIR}/devel/p5-Module-Recursive-Require \
		p5-Test-Spelling>=0:${PORTSDIR}/devel/p5-Test-Spelling
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
