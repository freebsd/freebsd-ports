PORTNAME=	CGI-Application-Plugin-HTMLPrototype
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Access to the prototype JavaScript library using HTML::Prototype

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-CGI-Application>=0:www/p5-CGI-Application \
		p5-HTML-Prototype>=0:www/p5-HTML-Prototype

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
