PORTNAME=	nettacker
DISTVERSION=	0.4.1
CATEGORIES=	security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	einar@isnic.is
COMMENT=	Automated penetration testing and information-gathering framework
WWW=		https://owasp.org/nettacker

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.0.0:devel/py-poetry-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.9.5:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}apsw>=3.50.0.0:databases/py-apsw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}argparse>=1.4.0:devel/py-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>=3.0.1:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}impacket>=0.11.0:net/py-impacket@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipaddr>=2.2.0:devel/py-ipaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}multiprocess>=0.70.15:devel/py-multiprocess@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.9.0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=3.4.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}py3dns>=4.0.0:dns/py-py3dns@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymysql>=1.1.1:databases/py-pymysql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyopenssl>=23.2.0:security/py-pyopenssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysocks>=1.7.1:net/py-pysocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.1:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>=2.0.22:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}texttable>=1.7.0:textproc/py-texttable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>=0.21.0:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zipp>=3.19.1:devel/py-zipp@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-asyncio>0:devel/py-pytest-asyncio@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}schema>0:devel/py-schema@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	OWASP
GH_PROJECT=	Nettacker
USE_PYTHON=	autoplist concurrent pep517 pytest

# Failed tests: https://github.com/OWASP/Nettacker/issues/1721
PYTEST_IGNORED_TESTS=	test_create_tcp_socket \
			test_logs_to_report_html_sqlite \
			test_logs_to_report_html_sqlalchemy

NO_ARCH=	yes

.include <bsd.port.mk>
