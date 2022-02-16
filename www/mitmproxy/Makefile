# Created by: Hung-Yi Chen <gaod@hychen.org>

PORTNAME=	mitmproxy
PORTVERSION=	7.0.4
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	www python

MAINTAINER=	gaod@hychen.org
COMMENT=	SSL-capable man-in-the-middle proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgiref>=3.2.10:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.4:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=1.0:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2019.9.11:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=3.3:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask>=1.1.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.11:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=4.0:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperframe>=6.0:www/py-hyperframe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kaitaistruct>=0.7:devel/py-kaitaistruct@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap3>=2.8:net/py-ldap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=2.0.0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.6.5:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.14:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=20.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.4.2:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.6.0:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.16:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.3:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.3:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=2.1.1:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsproto>=1.0.0:net/py-wsproto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}publicsuffix2>=2.20190812:dns/py-publicsuffix2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.11:archivers/py-zstandard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parver>0:devel/py-parver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		cpe python:3.8+
USE_PYTHON=	distutils autoplist noflavors
USE_GITHUB=	yes

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
