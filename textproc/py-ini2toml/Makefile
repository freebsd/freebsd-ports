# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	ini2toml
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Automatically conversion of .ini/.cfg files to TOML equivalents

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}packaging>=20.7:devel/py-packaging@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	FULL LITE
OPTIONS_DEFAULT=FULL
FULL_DESC=	Create TOML document with TOML-equivalent comment
LITE_DESC=	Create TOML document without comment

FULL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configupdater>=3.0.1<4:devel/py-configupdater@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}tomlkit>=0.10.0<2:textproc/py-tomlkit@${PY_FLAVOR}
LITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}tomli-w>=0.4.0<2:textproc/py-tomli-w@${PY_FLAVOR}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 30800 && (${PORT_OPTIONS:MFULL} || ${PORT_OPTIONS:MLITE})
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}importlib-metadata>=0:devel/py-importlib-metadata@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
