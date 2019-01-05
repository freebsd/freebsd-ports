# $FreeBSD$

PORTNAME=	Woothee
PORTVERSION=	1.8.0
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR= CPAN:TAGOMORIS
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Multi-language user-agent strings parsers (perl implementation)

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Module-Build>=0.38:devel/p5-Module-Build
TEST_DEPENDS=	p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-YAML>=0:textproc/p5-YAML

USES=		perl5

NO_ARCH=	yes
USE_PERL5=	modbuildtiny

.include <bsd.port.mk>
