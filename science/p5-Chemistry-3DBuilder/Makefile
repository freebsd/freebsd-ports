# Created by: Steve Wills <steve@mouf.net
# $FreeBSD$

PORTNAME=	Chemistry-3DBuilder
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generate 3D coordinates from a connection table

BUILD_DEPENDS=	p5-Chemistry-Mol>=0:science/p5-Chemistry-Mol \
		p5-Chemistry-File-SMILES>=0:science/p5-Chemistry-File-SMILES \
		p5-Chemistry-File-SMARTS>=0:science/p5-Chemistry-File-SMARTS \
		p5-Chemistry-Ring>=0:science/p5-Chemistry-Ring \
		p5-Chemistry-InternalCoords>=0:science/p5-Chemistry-InternalCoords \
		p5-Math-VectorReal>=0:math/p5-Math-VectorReal
RUN_DEPENDS=	p5-Chemistry-Mol>=0:science/p5-Chemistry-Mol \
		p5-Chemistry-File-SMILES>=0:science/p5-Chemistry-File-SMILES \
		p5-Chemistry-File-SMARTS>=0:science/p5-Chemistry-File-SMARTS \
		p5-Chemistry-Ring>=0:science/p5-Chemistry-Ring \
		p5-Chemistry-InternalCoords>=0:science/p5-Chemistry-InternalCoords \
		p5-Math-VectorReal>=0:math/p5-Math-VectorReal

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
