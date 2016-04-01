# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RPC-ExtDirect
PORTVERSION=	3.21
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Perl extension for implementing the Ext.Direct remoting protocol

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Attribute-Handlers>=0.93:devel/p5-Attribute-Handlers \
		p5-JSON>=2.53:converters/p5-JSON
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.46:devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
