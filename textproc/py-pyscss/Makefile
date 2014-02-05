# Created by: Ilya A. Arkhipov <rum1cro@yandex.ru>
# $FreeBSD$

PORTNAME=	pyscss
PORTVERSION=	1.2.0
CATEGORIES=	textproc python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rum1cro@yandex.ru
COMMENT=	Compiler for SCSS flavor of the Sass language

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:${PORTSDIR}/devel/py-pytest

USE_GITHUB=	yes
GH_ACCOUNT=	Kronuz
GH_COMMIT=	2c10593
GH_PROJECT=	pyScss
GH_TAGNAME=	v${PORTVERSION}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

regression-test: build
	@cd ${WRKSRC} && py.test

.include <bsd.port.mk>
