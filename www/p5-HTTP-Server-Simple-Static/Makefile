# $FreeBSD$

PORTNAME=	HTTP-Server-Simple-Static
PORTVERSION=	0.13
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Serve static files with HTTP::Server::Simple

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI>=3.46:www/p5-CGI \
		p5-File-LibMagic>=0:devel/p5-File-LibMagic \
		p5-HTTP-Server-Simple>=0:www/p5-HTTP-Server-Simple \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPEND}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
