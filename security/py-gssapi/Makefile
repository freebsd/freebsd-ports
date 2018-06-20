# $FreeBSD$

PORTNAME=	gssapi
DISTVERSION=	1.5.0
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	High-level and low-level Python bindings to GSSAPI C libraries

LICENSE=	ISCL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PY_ENUM34}

OPTIONS_RADIO=	GSSAPI
OPTIONS_RADIO_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_DEFAULT=	GSSAPI_BASE

GSSAPI_BASE_USES=	gssapi
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit

USES=	python
USE_PYTHON=	distutils autoplist

post-patch:
	${REINPLACE_CMD} -e 's|%%KRB5CONFIG%%|${KRB5CONFIG}|' ${WRKSRC}/setup.py

.include <bsd.port.mk>
