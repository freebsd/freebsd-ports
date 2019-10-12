# $FreeBSD$

PORTNAME=	App-RunCron
PORTVERSION=	0.08
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bokutin@bokut.in
COMMENT=	Making wrapper scripts for cron tasks

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Class-Accessor-Lite>=0:devel/p5-Class-Accessor-Lite \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny
TEST_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-File-pushd>=0:devel/p5-File-pushd \
		p5-Test-Exit>=0:devel/p5-Test-Exit \
		p5-Test-Requires>=0:devel/p5-Test-Requires \
		p5-Test-Mock-Guard>=0:devel/p5-Test-Mock-Guard

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
