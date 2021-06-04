PORTNAME=	jq
PORTVERSION=	1.1.3
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	jq.py: a lightweight and flexible JSON processor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libjq.so:textproc/jq \
		libonig.so:devel/oniguruma

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		localbase python:3.4+
USE_PYTHON=	autoplist distutils

post-install:
		${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/jq*.so

.include <bsd.port.mk>
