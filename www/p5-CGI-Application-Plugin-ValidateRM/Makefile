PORTNAME=	CGI-Application-Plugin-ValidateRM
PORTVERSION=	2.5.2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Help validate forms with the CGI::Application framework
WWW=		https://metacpan.org/release/CGI-Application-Plugin-ValidateRM

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-HTML-FillInForm>=0:www/p5-HTML-FillInForm \
		p5-Data-FormValidator>=0:textproc/p5-Data-FormValidator \
		p5-CGI-Application>=0:www/p5-CGI-Application

USES=		perl5
USE_PERL5=	modbuild

NO_ARCH=	yes

.include <bsd.port.mk>
