PORTNAME=	mitmproxy
DISTVERSIONPREFIX=	v
DISTVERSION=	12.3.1
CATEGORIES=	www python

MAINTAINER=	siva@FreeBSD.org
COMMENT=	SSL-capable man-in-the-middle proxy
WWW=		https://mitmproxy.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mypy>0:devel/py-mypy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdoc>0:devel/py-pdoc@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-timeout>0:devel/py-pytest-timeout@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-xdist>0:devel/py-pytest-xdist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}types-requests>0:devel/py-types-requests@${PY_FLAVOR}

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aioquic>0:www/py-aioquic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argon2-cffi>=23.1.0:security/py-argon2-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgiref>=3.2.10:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=5.0.0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}brotli>=1.2.1:archivers/py-brotli@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}certifi>=2026.10.19:security/py-certifi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=3.0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h11>=0.16.0:net/py-h11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=4.3.0:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hyperframe>=6.0:www/py-hyperframe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kaitaistruct>=0.10:devel/py-kaitaistruct@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap3>=2.8:net/py-ldap3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mitmproxy_rs>=0.12.15:www/py-mitmproxy_rs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=24.3:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=3.3.2:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyperclip>=1.9.0:devel/py-pyperclip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.18.10:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=2.3:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tornado>=6.5.0:www/py-tornado@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=2.6.14:devel/py-urwid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsproto>=1.0:net/py-wsproto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}publicsuffix2>=2.20190812:dns/py-publicsuffix2@${PY_FLAVOR}

py310_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.zstd>=1.7.0:devel/py-backports.zstd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.13.2:devel/py-typing-extensions@${PY_FLAVOR}
py311_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.zstd>=1.7.0:devel/py-backports.zstd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.13.2:devel/py-typing-extensions@${PY_FLAVOR}
py312_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.zstd>=1.7.0:devel/py-backports.zstd@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.13.2:devel/py-typing-extensions@${PY_FLAVOR}
py313_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}backports.zstd>=1.7.0:devel/py-backports.zstd@${PY_FLAVOR}

USES=		cpe python
USE_GITHUB=	yes
USE_PYTHON=	autoplist cryptography pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
