PORTNAME=	qrcode
PORTVERSION=	7.3
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	QR Code image generator
WWW=		https://github.com/lincolnloop/python-qrcode

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.8:devel/py-six@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	${REINPLACE_CMD} -e 's|share/\(man/man1\)|\1|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
