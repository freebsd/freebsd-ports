# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Catalyst-Engine-HTTP-Prefork
PORTVERSION=	0.51
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	High-performance pre-forking Catalyst engine

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7012:www/p5-Catalyst-Runtime \
		p5-Net-Server>=0.97:net/p5-Net-Server \
		p5-HTTP-HeaderParser-XS>=0:www/p5-HTTP-HeaderParser-XS \
		p5-CGI-Cookie-XS>=0:www/p5-CGI-Cookie-XS \
		p5-HTTP-Body>=0:www/p5-HTTP-Body
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	${REINPLACE_CMD} -i '' -e 's/Cookie::XS/CGI::Cookie::XS/g' \
		${WRKSRC}/lib/Catalyst/Engine/HTTP/Prefork/Handler.pm

.include <bsd.port.mk>
