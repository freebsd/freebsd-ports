# $FreeBSD$

PORTNAME=	Net-Groonga-HTTP
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for Groonga httpd client library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	\
	p5-Data-Page>0:databases/p5-Data-Page \
	p5-Furl>0:www/p5-Furl \
	p5-JSON-XS>0:converters/p5-JSON-XS \
	p5-Mouse>0:devel/p5-Mouse \
	p5-URI>0:net/p5-URI
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
NO_ARCH=	YES

.include <bsd.port.mk>
