# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	FormValidator-Lite
PORTVERSION=	0.39
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightleight form validation library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor-Lite>=0.05:devel/p5-Class-Accessor-Lite \
		p5-Class-Load>=0.11:devel/p5-Class-Load \
		p5-Email-Valid>=0:mail/p5-Email-Valid \
		p5-Email-Valid-Loose>=0:mail/p5-Email-Valid-Loose
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Requires>=0.05:devel/p5-Test-Requires \
		p5-Text-TestBase>=0:textproc/p5-Text-TestBase \
		p5-YAML>=0:textproc/p5-YAML

NO_ARCH=	yes
USE_PERL5=	modbuildtiny
USES=		perl5

.include <bsd.port.mk>
