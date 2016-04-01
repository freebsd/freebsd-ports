# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	McBain-WithPSGI
PORTVERSION=	2.001001
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:IDOPEREL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Load a McBain API as a RESTful PSGI web service

LICENSE=	GPLv1 ARTPERL10
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-McBain>=0:www/p5-McBain \
		p5-JSON-MaybeXS>=0:converters/p5-JSON-MaybeXS \
		p5-Plack>=1.0029:www/p5-Plack

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
