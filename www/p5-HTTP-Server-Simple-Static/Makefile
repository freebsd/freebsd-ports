# $FreeBSD$

PORTNAME=	HTTP-Server-Simple-Static
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Serve static files with HTTP::Server::Simple

RUN_DEPENDS=	p5-File-LibMagic>=0:${PORTSDIR}/devel/p5-File-LibMagic \
		p5-HTTP-Server-Simple>=0:${PORTSDIR}/www/p5-HTTP-Server-Simple \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

MAN3=	HTTP::Server::Simple::Static.3

NO_STAGE=	yes
.include <bsd.port.mk>
