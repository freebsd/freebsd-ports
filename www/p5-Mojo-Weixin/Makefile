# $FreeBSD$

PORTNAME=	Mojo-Weixin
PORTVERSION=	1.4.6
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SJDY
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Weixin Client Framework base on Mojolicious

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Encode-Locale>=0:converters/p5-Encode-Locale \
		p5-IO-Socket-SSL>=2.009:security/p5-IO-Socket-SSL \
		p5-Mojolicious>=8.02:www/p5-Mojolicious

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
