# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-Geometry-Planar-GPC-Polygon
PORTVERSION=	0.05
PORTREVISION=	4
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	OO wrapper to gpc library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Inline>=0:${PORTSDIR}/devel/p5-Inline \
		p5-Inline-C>=0:${PORTSDIR}/devel/p5-Inline-C
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
