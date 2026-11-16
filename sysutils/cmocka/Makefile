PORTNAME=	cmocka
DISTVERSION=	2.0.2
CATEGORIES=	sysutils
MASTER_SITES=	https://cmocka.org/files/${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unit testing framework for C with support for mock objects
WWW=		https://cmocka.org/ \
		https://gitlab.com/cmocka/cmocka

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:testing pathfix tar:xz
USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	UNIT_TESTING

.include <bsd.port.mk>
