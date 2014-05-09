# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Geometry-Planar
PORTVERSION=	1.18
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}-withoutworldwriteables

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Collection of planar geometry functions

LICENSE=	ART10

BUILD_DEPENDS=	p5-Math-Geometry-Planar-GPC>=0:${PORTSDIR}/math/p5-Math-Geometry-Planar-GPC \
		p5-Math-Geometry-Planar-Offset>=0:${PORTSDIR}/math/p5-Math-Geometry-Planar-Offset
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
