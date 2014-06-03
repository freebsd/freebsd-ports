# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	FormValidator-Lite
PORTVERSION=	0.37
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightleight form validation library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Class-Accessor-Lite>=0.05:${PORTSDIR}/devel/p5-Class-Accessor-Lite \
		p5-Class-Load>=0.11:${PORTSDIR}/devel/p5-Class-Load \
		p5-Email-Valid>0:${PORTSDIR}/mail/p5-Email-Valid \
		p5-Email-Valid-Loose>0:${PORTSDIR}/mail/p5-Email-Valid-Loose \
		p5-Filter>0:${PORTSDIR}/devel/p5-Filter
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Text-TestBase>0:${PORTSDIR}/textproc/p5-Text-TestBase \
		p5-Test-Requires>=0.05:${PORTSDIR}/devel/p5-Test-Requires \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
