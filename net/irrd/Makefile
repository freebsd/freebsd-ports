PORTNAME=	irrd
PORTVERSION=	4.2.4
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	4

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Internet Routing Registry database server v4

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

#ariadne==0.14.1
#hiredis==2.0.0
#ordered-set==4.0.2
#pydantic==1.9.0
#python-gnupg==0.4.8
#pytz==2022.1
#redis==4.2.0
#PyYAML==6.0
BUILD_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}alembic>=1.7.7:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asgiref>=3.4.1:www/py-asgiref@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=3.2.0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifultable>=0.8.0:devel/py-beautifultable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemon>=2.3.0:devel/py-daemon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}datrie>=0.8.2:devel/py-datrie@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hiredis>=0.2.0:databases/py-hiredis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipy>=1.01:net-mgmt/py-ipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ordered-set>=3.1.1:devel/py-ordered-set@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.7.4:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pid>=3.0.4:devel/py-pid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=5.9.0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.9.3:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2cffi>=2.9.0:databases/py-psycopg2cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.8.2:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>=0.4.7:security/py-python-gnupg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2021.3:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3.5.3:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.27.1:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.2.2:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.16.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy14>=1.3.24:databases/py-sqlalchemy14@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}starlette>=0.17.1:www/py-starlette@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ujson>=4.3.0:devel/py-ujson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.16.0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.4.1:devel/py-yaml@${PY_FLAVOR}
#pytest-cov==3.0.0
#python-graphql-client==0.4.2
TEST_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}coverage>=6.2:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.9.0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-env>=0.6.2:devel/py-pytest-env@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=7.0.1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=22.2.0:devel/py-twisted@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
GH_ACCOUNT=	irrdnet
GH_PROJECT=	${PORTNAME}
USE_PYTHON=	autoplist concurrent distutils
USE_RC_SUBR=	irrd4

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	GROUPS=${GROUPS} \
		PGSQL_DEFAULT=${PGSQL_DEFAULT} \
		PYTHON_CMD="${PYTHON_CMD}" \
		USERS=${USERS}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	"@sample etc/${PORTNAME}${PKGNAMESUFFIX}.yaml.sample"

OPTIONS_DEFINE=		DOCS
#sphinxcontrib-spelling==7.3.2
#sphinx-material==0.0.35
DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=4.3.2:textproc/py-sphinx@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/irrd.yaml|${PREFIX}/etc/irrd.yaml|g' \
		${WRKSRC}/docs/users/mirroring.rst \
		${WRKSRC}/docs/admins/configuration.rst \
		${WRKSRC}/docs/admins/deployment.rst \
		${WRKSRC}/irrd/conf/__init__.py

post-install:
	${INSTALL_DATA} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/conf/default_config.yaml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}.yaml.sample

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} pytest ${PORTNAME})

.include <bsd.port.mk>
