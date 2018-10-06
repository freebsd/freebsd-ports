# $FreeBSD$

PORTNAME=	Text-Colorizer
PORTVERSION=	0.02.2
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:NKH
PKGNAMEPREFIX=	p5-

MAINTAINER=	gebhart@secnetix.de
COMMENT=	Create colored text from text and color description

LICENSE=	ART20 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Readonly>=0:devel/p5-Readonly \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
