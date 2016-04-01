# Created by: Sergey Osokin aka oZZ <ports@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-TableExtract
PORTVERSION=	2.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract text contained in tables within an HTML document

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-HTML-Element-Extended>=1.17:www/p5-HTML-Element-Extended \
		p5-HTML-Parser>=0:www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
