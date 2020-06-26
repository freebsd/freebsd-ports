# $FreeBSD$

PORTNAME=	HTTP-Engine
PORTVERSION=	0.03005
PORTREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for HTTP Server Engine Drivers

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	\
	p5-Any-Moose>=0.13:devel/p5-Any-Moose \
	p5-CGI-Simple>=1.103:www/p5-CGI-Simple \
	p5-Filter>0:devel/p5-Filter \
	p5-HTTP-Body>=1.05:www/p5-HTTP-Body \
	p5-HTTP-Headers-Fast>=0.11:www/p5-HTTP-Headers-Fast \
	p5-HTTP-Server-Simple>=0.35:www/p5-HTTP-Server-Simple \
	p5-Mouse>=0.62:devel/p5-Mouse \
	p5-URI>=1.36:net/p5-URI
TEST_DEPENDS=	\
	p5-HTTP-Request-AsCGI>0:www/p5-HTTP-Request-AsCGI \
	p5-YAML>0:textproc/p5-YAML \
	p5-IO-Stringy>0:devel/p5-IO-Stringy \
	p5-MouseX-Types>=0.05:devel/p5-MouseX-Types

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
