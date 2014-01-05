# Created by: Tom Judge <tj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	RPC-ExtDirect
PORTVERSION=	2.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Perl extension for implimenting the Ext.Direct remoting protocol

BUILD_DEPENDS=	p5-Attribute-Handlers>=0.93:${PORTSDIR}/devel/p5-Attribute-Handlers \
		p5-JSON>=2.53:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Pod>=1.46:${PORTSDIR}/devel/p5-Test-Pod

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
