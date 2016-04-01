# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	HTML-WikiConverter-TikiWiki
PORTVERSION=	0.50
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Convert HTML to TikiWiki markup

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-WikiConverter>=0.54:www/p5-HTML-WikiConverter \
		p5-URI>=1.35:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
