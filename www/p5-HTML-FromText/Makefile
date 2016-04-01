# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=		HTML-FromText
PORTVERSION=		2.07
PORTREVISION=	1
CATEGORIES=		www perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-

MAINTAINER=		danilo@FreeBSD.org
COMMENT=	Mark up text as HTML

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Email-Find>=0.09:mail/p5-Email-Find \
		p5-HTML-Parser>=1.26:www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
