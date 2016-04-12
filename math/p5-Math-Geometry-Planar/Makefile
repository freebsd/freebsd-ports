# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Geometry-Planar
PORTVERSION=	1.18
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}-withoutworldwriteables

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Collection of planar geometry functions

LICENSE=	ART10

BUILD_DEPENDS=	p5-Math-Geometry-Planar-GPC>=0:math/p5-Math-Geometry-Planar-GPC \
		p5-Math-Geometry-Planar-Offset>=0:math/p5-Math-Geometry-Planar-Offset
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
