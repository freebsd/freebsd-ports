# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Text-TestBase
PORTVERSION=	0.13
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Parser for Test::Base format

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>0:devel/p5-Test-Requires

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
