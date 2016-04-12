# $FreeBSD$

PORTNAME=	Catalyst-Engine-PSGI
PORTVERSION=	0.14
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension of PSGI engine for Catalyst

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Catalyst-Runtime>=5.80007:www/p5-Catalyst-Runtime \
	p5-Catalyst-Action-RenderView>0:www/p5-Catalyst-Action-RenderView
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuildtiny
NO_ARCH=	YES

.include <bsd.port.mk>
