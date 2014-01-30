# Created by: tobez
# $FreeBSD$

PORTNAME=	Graph
PORTVERSION=	0.96
PORTEPOCH=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Graph, the Perl module for graph operations

BUILD_DEPENDS=	p5-Heap>=0:${PORTSDIR}/devel/p5-Heap \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
