# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	WWW-Comic
PORTVERSION=	1.06
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieve comic strip images

LICENSE=	APACHE20

BUILD_DEPENDS=	p5-WWW-Dilbert>=1.19:www/p5-WWW-Dilbert \
		p5-WWW-VenusEnvy>=1.10:www/p5-WWW-VenusEnvy
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild
CONFIGURE_ARGS=	</dev/null

.include <bsd.port.mk>
