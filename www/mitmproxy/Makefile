PORTNAME=	mitmproxy
PORTVERSION=	7.0.4
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	www python

MAINTAINER=	gaod@hychen.org
COMMENT=	SSL-capable man-in-the-middle proxy
WWW=		https://mitmproxy.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		incorrect depends: depends on package: py38-asgiref>=3.2.10<3.5, py38-wsproto>=1.0.0<1.1

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asgiref>=3.2.10<3.5:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blinker>=1.4<1.5:devel/py-blinker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=1.0<1.1:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2019.9.11:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=7.0<8.1:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=1.1.1<2.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.11<0.13:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=4.0<5:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperframe>=6.0<7:www/py-hyperframe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kaitaistruct>=0.7<0.10:devel/py-kaitaistruct@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap3>=2.8<2.10:net/py-ldap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=2.0.0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=1.0.0<1.1.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=20.0<20.1:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.6.5<1.8:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=3.14<3.19:devel/py-protobuf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}publicsuffix2>=2.20190812<3:dns/py-publicsuffix2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.4.2<2.5:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.6.0<1.9:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.16<0.17.17:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.3<2.5:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=4.3<7:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=2.1.1<2.2:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsproto>=1.0.0<1.1:net/py-wsproto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zstandard>=0.11<0.16:archivers/py-zstandard@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parver>0:devel/py-parver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		cpe python
USE_GITHUB=	yes
USE_PYTHON=	autoplist cryptography distutils noflavors

NO_ARCH=	yes

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -rs -v

.include <bsd.port.mk>
