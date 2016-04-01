# $FreeBSD$

PORTNAME=	HTTP-Server-Simple-Static
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Serve static files with HTTP::Server::Simple

RUN_DEPENDS=	p5-File-LibMagic>=0:devel/p5-File-LibMagic \
		p5-HTTP-Server-Simple>=0:www/p5-HTTP-Server-Simple \
		p5-URI>=0:net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>
