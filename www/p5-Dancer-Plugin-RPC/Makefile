# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-RPC
PORTVERSION=	1.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ABELTJE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Configure endpoints for XMLRPC and JSONRPC procedures

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Dancer>=1.3100:www/p5-Dancer \
		p5-JSON>=2.0:converters/p5-JSON \
		p5-Params-ValidationCompiler>=0.24:devel/p5-Params-ValidationCompiler \
		p5-RPC-XML>=0.56:net/p5-RPC-XML \
		p5-Type-Tiny>=1:devel/p5-Type-Tiny
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Fatal>=0.010:devel/p5-Test-Fatal \
		p5-Test-NoWarnings>=1:devel/p5-Test-NoWarnings

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

PORTSCOUT=	limit:^[0-9\.]*$$

.include <bsd.port.mk>
