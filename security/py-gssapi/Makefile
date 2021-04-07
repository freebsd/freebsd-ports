PORTNAME=	gssapi
DISTVERSION=	1.6.9
CATEGORIES=	security python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	john@saltant.com
COMMENT=	High-level and low-level Python bindings to GSSAPI C libraries

LICENSE=	ISCL

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>1.4.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR}

USES=	python:3.6+
USE_PYTHON=	distutils autoplist

OPTIONS_RADIO=	GSSAPI
OPTIONS_RADIO_GSSAPI=	GSSAPI_BASE GSSAPI_HEIMDAL GSSAPI_MIT
OPTIONS_DEFAULT=	GSSAPI_BASE

GSSAPI_BASE_USES=	gssapi ssl
GSSAPI_HEIMDAL_USES=	gssapi:heimdal
GSSAPI_MIT_USES=	gssapi:mit

post-patch:
	${REINPLACE_CMD} -e 's|%%KRB5CONFIG%%|${KRB5CONFIG}|' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/raw/*.so

.include <bsd.port.mk>
