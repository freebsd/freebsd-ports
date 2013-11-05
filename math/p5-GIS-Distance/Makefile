# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	GIS-Distance
PORTVERSION=	0.08
PORTEPOCH=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BLUEFEET
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Calculate geographic distances

BUILD_DEPENDS=	p5-Any-Moose>=0.18:${PORTSDIR}/devel/p5-Any-Moose \
		p5-Class-Measure>=0:${PORTSDIR}/devel/p5-Class-Measure \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Mouse>=0.48:${PORTSDIR}/devel/p5-Mouse \
		p5-namespace-autoclean>=0:${PORTSDIR}/devel/p5-namespace-autoclean
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
