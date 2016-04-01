# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	HTTP-Server-Simple-Authen
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	www security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Authentication plugin for HTTP::Server::Simple

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Authen-Simple>=0.4:security/p5-Authen-Simple \
		p5-HTTP-Server-Simple>=0.16:www/p5-HTTP-Server-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5 shebangfix

SHEBANG_FILES=	server.pl

.include <bsd.port.mk>
