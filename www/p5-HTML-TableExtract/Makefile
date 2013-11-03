# Created by: Sergey Osokin aka oZZ <ports@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTML-TableExtract
PORTVERSION=	2.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract text contained in tables within an HTML document

BUILD_DEPENDS=	p5-HTML-Element-Extended>=1.17:${PORTSDIR}/www/p5-HTML-Element-Extended \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
RUN_DEPENDS=	p5-HTML-Element-Extended>=1.17:${PORTSDIR}/www/p5-HTML-Element-Extended \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
