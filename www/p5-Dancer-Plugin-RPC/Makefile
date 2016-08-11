# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-RPC
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ABELTJE
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Configure endpoints for XML and/or JSON RPC routes

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Dancer>=1.3202:www/p5-Dancer \
	p5-Plack>=1.0002:www/p5-Plack \
	p5-Params-Validate>=1.0:devel/p5-Params-Validate \
	p5-JSON>=2.0:converters/p5-JSON \
	p5-RPC-XML>=0.79:net/p5-RPC-XML
BUILD_DEPENDS:=	${RUN_DEPENDS}
TEST_DEPENDS=p5-Test-Fatal>0.010:devel/p5-Test-Fatal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
