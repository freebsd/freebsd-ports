# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	Catalyst-Plugin-Params-Nested
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nested params (ala Ruby on Rails or PHP-style param arrays)

BUILD_DEPENDS=	p5-CGI-Expand>=1.06:${PORTSDIR}/www/p5-CGI-Expand \
		p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
