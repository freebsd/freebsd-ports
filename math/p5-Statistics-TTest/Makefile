# Created by: dawe <daweonline@gmail.com>
# $FreeBSD$

PORTNAME=	Statistics-TTest
PORTVERSION=	1.1.0
PORTREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Statistics
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to perform T-test on 2 independent samples

BUILD_DEPENDS=	p5-Statistics-Descriptive>=0:${PORTSDIR}/math/p5-Statistics-Descriptive \
		p5-Statistics-Distributions>=0.07:${PORTSDIR}/math/p5-Statistics-Distributions
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
