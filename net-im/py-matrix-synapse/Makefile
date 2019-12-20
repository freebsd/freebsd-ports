# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	matrix-synapse
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
CATEGORIES=	net-im python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@skyforge.at
COMMENT=	Matrix protocol reference homeserver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# Keep the RUN_DEPENDS layout similar to the master/synapse/python_dependencies.py file
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=2.5.1:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozendict>=1:devel/py-frozendict@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unpaddedbase64>=1.1.0:devel/py-unpaddedbase64@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}canonicaljson>=1.1.3:devel/py-canonicaljson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}signedjson>=1.0.0:security/py-signedjson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.2.1:security/py-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>=2.5:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=18.1.0:security/py-service_identity@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=18.9.0:devel/py-twisted@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}treq>=15.1:www/py-treq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.0.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.9:devel/py-pyasn1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1-modules>=0.0.7:devel/py-pyasn1-modules@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemonize>=2.4.2:devel/py-daemonize@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=4.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sortedcontainers>=1.4.4:devel/py-sortedcontainers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=4.5.2:security/py-pysaml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymacaroons-pynacl>=0.13.0:security/py-pymacaroons-pynacl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.5.2:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonenumbers>=8.2.0:devel/py-phonenumbers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prometheus-client>=0.2.0:net-mgmt/py-prometheus-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}attrs>17.4.0:devel/py-attrs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.18:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=3.10.0:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.9:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=1.4.3:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}typing-extensions>=3.7.4:devel/py-typing-extensions@${PY_FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}virtualenv>=15.0:devel/py-virtualenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=2.3.1:devel/py-tox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=2.0:devel/py-mock@${PY_FLAVOR}

USES=		python:3.5+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	matrix-org
GH_PROJECT=	synapse

USE_RC_SUBR=	synapse

USERS=		synapse
GROUPS=		synapse

DBDIR?=		/var/db/${PORTNAME}
LOGDIR?=	/var/log/${PORTNAME}
PIDDIR?=	/var/run/${PORTNAME}

SUB_FILES=	pkg-message log.config
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} DBDIR=${DBDIR} LOGDIR=${LOGDIR} PIDDIR=${PIDDIR} USERS=${USERS}

PLIST_FILES=	"@sample ${ETCDIR}/log.config.sample"
DOCS=README.rst UPGRADE.rst CHANGES.md docs/postgres.md
PORTDOCS=${DOCS:T}

NO_ARCH=	yes

OPTIONS_DEFINE=		LDAP PGSQL SQLITE URLPREVIEW DOCS
OPTIONS_DEFAULT=	SQLITE PGSQL DOCS

URLPREVIEW_DESC=	Add dependencies necessary for URL previews

LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matrix-synapse-ldap3>=0.1:net/py-matrix-synapse-ldap3@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>2.7:databases/py-psycopg2@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
URLPREVIEW_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>=3.5.0:devel/py-lxml@${PY_FLAVOR}

do-test:
	cd ${WRKSRC} && PYTHONPATH="." trial-${PYTHON_VER} tests

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/log.config ${STAGEDIR}${ETCDIR}/log.config.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
