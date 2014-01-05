# Created by: Vladimir Timofeev <vovkasm@gmail.com>
# $FreeBSD$

PORTNAME=	Catalyst-Model-Adaptor
PORTVERSION=	0.10
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vovkasm@gmail.com
COMMENT=	Use a plain class as a Catalyst model

RUN_DEPENDS=	p5-Catalyst-Runtime>=0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-MRO-Compat>=0:${PORTSDIR}/devel/p5-MRO-Compat
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Test-use-ok>=0:${PORTSDIR}/devel/p5-Test-use-ok \
		p5-Test-WWW-Mechanize-Catalyst>=0:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
