PORTNAME=	matrix-synapse
DISTVERSION=	1.131.0
PORTREVISION=	3
CATEGORIES=	net-im python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME:S/-/_/}-${DISTVERSION}.tar.gz

MAINTAINER=	ports@skyforge.at
COMMENT=	Matrix protocol reference homeserver
WWW=		https://element-hq.github.io/synapse

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE-AGPL-3.0

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}poetry-core>=1.1.0<2.1.3_99:devel/py-poetry-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-rust>=1.3:devel/py-setuptools-rust@${PY_FLAVOR}
# Keep the RUN_DEPENDS layout similar to the pyproject.toml file
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=3.0.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}immutabledict>=2.0:devel/py-immutabledict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unpaddedbase64>=2.1.0:devel/py-unpaddedbase64@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}canonicaljson>=2.0.0<3.0.0:devel/py-canonicaljson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}signedjson>=1.1.0<2.0.0:security/py-signedjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service-identity>=18.1.0:security/py-service-identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=18.9.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}treq>=15.1:www/py-treq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.0.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=5.3:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.9:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.0.7:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.7:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=1.5.2:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymacaroons>=0.13.0:security/py-pymacaroons@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.5.2:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonenumbers>=8.2.0:devel/py-phonenumbers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.4.0:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>=19.2.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.18:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=1.4.3:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=4.1:devel/py-typing-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ijson>=3.1.4:devel/py-ijson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matrix-common>=1.3.0<2.0.0:devel/py-matrix-common@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=20.0:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic>=1.7.4:devel/py-pydantic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=4.5.0:security/py-pysaml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-multipart>=0.0.9:www/py-python-multipart@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}virtualenv>=15.0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=2.3.1:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>4.5.2:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}parameterized>=0.7.4:devel/py-parameterized@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}authlib>=0.15.1:security/py-authlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.5:dns/py-idna@${PY_FLAVOR}

USES=		cargo python shebangfix
USE_PYTHON=	autoplist cryptography pep517
USE_RC_SUBR=	synapse
WRKSRC=		${WRKDIR}/${PORTNAME:S/-/_/}-${DISTVERSION}
CARGO_CONFIGURE=	yes
CARGO_BUILD=	no
CARGO_TEST=	no
CARGO_INSTALL=	no
CARGO_CARGOTOML=	${WRKSRC}/rust/Cargo.toml

SHEBANG_FILES=	synapse/_scripts/*.py
SUB_FILES=	pkg-message log.config
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} DBDIR=${DBDIR} LOGDIR=${LOGDIR} PIDDIR=${PIDDIR} USERS=${USERS}

USERS=		synapse
GROUPS=		synapse

DBDIR?=		/var/db/${PORTNAME}
LOGDIR?=	/var/log/${PORTNAME}
PIDDIR?=	/var/run/${PORTNAME}

PLIST_FILES=	"@sample ${ETCDIR}/log.config.sample"

DOCS=		README.rst UPGRADE.rst CHANGES.md docs/postgres.md
PORTDOCS=	${DOCS:T}

OPTIONS_DEFINE=		DOCS JWT LDAP OIDC PGSQL REDIS SQLITE URLPREVIEW
OPTIONS_DEFAULT=	PGSQL SQLITE

JWT_DESC=		Add dependencies for JSON web tokens
OIDC_DESC=		Add dependencies for OpenID Connect based logins
REDIS_DESC=		Add support replication over Redis for synapse workers
URLPREVIEW_DESC=	Add dependencies necessary for URL previews

JWT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authlib>=0.15.1:security/py-authlib@${PY_FLAVOR}
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matrix-synapse-ldap3>=0.1:net/py-matrix-synapse-ldap3@${PY_FLAVOR}
OIDC_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}authlib>=0.15.1:security/py-authlib@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>2.8:databases/py-psycopg2@${PY_FLAVOR}
REDIS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hiredis>=0:databases/py-hiredis@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}txredisapi>=1.4.7:databases/py-txredisapi@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
URLPREVIEW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>=4.2.0:devel/py-lxml5@${PY_FLAVOR}

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/log.config ${STAGEDIR}${ETCDIR}/log.config.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

do-test:
	cd ${WRKSRC} && PYTHONPATH="${STAGEDIR}/${PYTHON_SITELIBDIR}:." trial-${PYTHON_VER} -j 4 tests

.include <bsd.port.mk>
