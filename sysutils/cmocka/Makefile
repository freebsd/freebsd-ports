PORTNAME=	cmocka
DISTVERSION=	2.0.0
CATEGORIES=	sysutils
MASTER_SITES=	https://cmocka.org/files/2.0/

MAINTAINER=	diizzy@FreeBSD.org
COMMENT=	Unit testing framework for C with support for mock objects
WWW=		https://cmocka.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing pathfix tar:xz
USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	UNIT_TESTING

.include <bsd.port.mk>
