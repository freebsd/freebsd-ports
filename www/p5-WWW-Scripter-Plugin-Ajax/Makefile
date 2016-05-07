# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	WWW-Scripter-Plugin-Ajax
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	WWW::Scripter plugin that provides the XMLHttpRequest object

RUN_DEPENDS=	p5-WWW-Scripter-Plugin-JavaScript>0:www/p5-WWW-Scripter-Plugin-JavaScript \
		p5-XML-DOM-Lite>0:textproc/p5-XML-DOM-Lite
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
