# Created by: Neil Booth
# $FreeBSD$

PORTNAME=	qrcode
PORTVERSION=	6.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	leres@FreeBSD.org
COMMENT=	QR Code image generator

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=1.8:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=2.6:graphics/py-pillow@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent distutils

post-patch:
	${REINPLACE_CMD} -e 's|share/\(man/man1\)|\1|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
