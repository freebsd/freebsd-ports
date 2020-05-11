# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	irrd
PORTVERSION=	4.0.8
DISTVERSIONPREFIX=	v
CATEGORIES=	net python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	4

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Internet Routing Registry database server v4

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

#python-gnupg==0.4.4 needs updating
#twisted==19.2.1 needs updating
BUILD_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}alembic>=1.0.10:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}beautifultable>=0.7.0:devel/py-beautifultable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dotted>=0.1.8:devel/py-dotted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ipy>=1.00:net-mgmt/py-ipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ordered-set>=3.1.1:devel/py-ordered-set@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.7.1:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8.2:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>=0.4.3:security/py-python-gnupg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=18.9.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ujson>=1.35:devel/py-ujson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.1:devel/py-yaml@${PY_FLAVOR}
TEST_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}coverage>=4.5.3:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=4.4.1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=2.6.1:devel/py-pytest-cov@${PY_FLAVOR}

USES=		pgsql python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils
USE_RC_SUBR=	irrd4

GH_ACCOUNT=	irrdnet
GH_PROJECT=	${PORTNAME}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

OPTIONS_DEFINE=	DOCS
DOCS_BUILD_DEPENDS=	${PY_SPHINX}

PLIST_FILES=	"@sample etc/${PORTNAME}${PKGNAMESUFFIX}.yaml.sample"
NO_ARCH=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD="${PYTHON_CMD}" \
		PGSQL_DEFAULT=${PGSQL_DEFAULT} \
		USERS=${USERS} \
		GROUPS=${GROUPS}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3700
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}dataclasses>=0.6:devel/py-dataclasses@${PY_FLAVOR}
.endif

post-install:
	${INSTALL_DATA} ${STAGEDIR}${PYTHON_SITELIBDIR}/${PORTNAME}/conf/default_config.yaml \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}${PKGNAMESUFFIX}.yaml.sample

do-test:
	@(cd ${TEST_WRKSRC} && ${SETENV} pytest ${PORTNAME})

.include <bsd.port.post.mk>
