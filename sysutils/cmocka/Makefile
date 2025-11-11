PORTNAME=	cmocka
DISTVERSION=	1.1.8
CATEGORIES=	sysutils
MASTER_SITES=	https://cmocka.org/files/${DISTVERSION:R}/

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Unit testing framework for C with support for mock objects
WWW=		https://cmocka.org/ \
		https://gitlab.com/cmocka/cmocka

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:testing pathfix tar:xz
USE_LDCONFIG=	yes

CMAKE_TESTING_ON=	UNIT_TESTING

.include <bsd.port.mk>
