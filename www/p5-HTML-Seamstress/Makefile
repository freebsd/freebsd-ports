# Created by: chinsan
# $FreeBSD$

PORTNAME=	HTML-Seamstress
PORTVERSION=	5.0h
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTML::Tree subclass for HTML templating via tree rewriting

BUILD_DEPENDS=	p5-Class-Prototyped>=0:${PORTSDIR}/devel/p5-Class-Prototyped \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
		p5-HTML-Element-Library>=0:${PORTSDIR}/www/p5-HTML-Element-Library \
		p5-HTML-Element-Replacer>=0:${PORTSDIR}/www/p5-HTML-Element-Replacer \
		p5-HTML-PrettyPrinter>=0:${PORTSDIR}/www/p5-HTML-PrettyPrinter \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
