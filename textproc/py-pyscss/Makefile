# Created by: Ilya A. Arkhipov <rum1cro@yandex.ru>
# $FreeBSD$

PORTNAME=	pyscss
PORTVERSION=	1.2.0
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Compiler for SCSS flavor of the Sass language

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
LIB_DEPENDS=	libpcre.so:devel/pcre
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Kronuz
GH_PROJECT=	pyScss

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		python
USE_PYTHON=	distutils autoplist

regression-test: build
	@cd ${WRKSRC} && py.test

.include <bsd.port.mk>
