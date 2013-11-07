# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Catalyst-View-Templated
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:JROCKWAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generic base class for template-based views

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Component-ACCEPT_CONTEXT>=0:${PORTSDIR}/www/p5-Catalyst-Component-ACCEPT_CONTEXT \
		p5-Class-C3>=0:${PORTSDIR}/devel/p5-Class-C3
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject \
		p5-Test-WWW-Mechanize-Catalyst>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst \
		p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
