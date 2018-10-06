# $FreeBSD$

PORTNAME=	Template-Plugin-JSON
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Adds a .json vmethod for all TT values

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-JSON>=2.12:converters/p5-JSON \
		p5-Moose>0:devel/p5-Moose \
		p5-Template-Toolkit>=2.20:www/p5-Template-Toolkit

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
