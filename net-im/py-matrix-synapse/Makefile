# Created by: Brendan Molloy <brendan+freebsd@bbqsrc.net>
# $FreeBSD$

PORTNAME=	matrix-synapse
DISTVERSIONPREFIX=	v
DISTVERSION=	0.25.0
PORTREVISION=	0
CATEGORIES=	net-im python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Matrix protocol reference homeserver

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# Keep the RUN_DEPENDS layout similar to the master/synapse/python_dependencies.py file
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jsonschema>=2.5.1:devel/py-jsonschema@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}frozendict>=0.5:devel/py-frozendict@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}unpaddedbase64>=1.1.0:devel/py-unpaddedbase64@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}canonicaljson>=1.0.0:devel/py-canonicaljson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}signedjson>=1.0.0:security/py-signedjson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynacl>=1.0.1:security/py-pynacl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}service_identity>=16.0:security/py-service_identity@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=16.6.0:devel/py-twisted@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.0.0:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.11:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyasn1>=0.1.9:devel/py-pyasn1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}daemonize>=2.4.2:devel/py-daemonize@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=0.4:security/py-bcrypt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=3.1.1:graphics/py-pillow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydenticon>=0.2:devel/py-pydenticon@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ujson>=1.35:devel/py-ujson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}blist>=1.3.6:devel/py-blist@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=4.0.2:security/py-pysaml2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymacaroons-pynacl>=0.9.3:security/py-pymacaroons-pynacl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.3.0:devel/py-msgpack-python@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}phonenumbers>=8.2.0:devel/py-phonenumbers@${FLAVOR}

# Conditional requirements that aren't so conditional
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}matrix-angular-sdk>=0.6.6:devel/py-matrix-angular-sdk@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>0:net/py-netaddr@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${FLAVOR}

# Dependencies that aren't declared in python_dependencies.py which I have discovered
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=3.10.0:devel/py-simplejson@${FLAVOR} \
		${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}virtualenv>=15.0:devel/py-virtualenv@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tox>=2.3.1:devel/py-tox@${FLAVOR}

USES=		python
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

SUB_FILES=	pkg-message homeserver.yaml log.config
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD} DBDIR=${DBDIR} LOGDIR=${LOGDIR} PIDDIR=${PIDDIR} USERS=${USERS}

PLIST_FILES+=	"@sample %%ETCDIR%%/homeserver.yaml.sample"
PLIST_FILES+=	"@sample %%ETCDIR%%/log.config.sample"

NO_ARCH=	yes

OPTIONS_DEFINE=	EMAIL LDAP PGSQL SQLITE
OPTIONS_DEFAULT=	SQLITE
EMAIL_DESC=	Email notifications for missed messages
EMAIL_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Jinja2>=2.8:devel/py-Jinja2@${FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}bleach>=1.4.2:www/py-bleach@${FLAVOR}
LDAP_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}matrix-synapse-ldap3>=0.1:net/py-matrix-synapse-ldap3@${FLAVOR}
PGSQL_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${FLAVOR}
SQLITE_RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}

.include <bsd.port.options.mk>

do-test:
	# -epy27 added to skip running python packaging and other dist tests
	@(cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${TEST_TARGET} \
		-a "-epy27")

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/homeserver.yaml ${STAGEDIR}${ETCDIR}/homeserver.yaml.sample
	${INSTALL_DATA} ${WRKDIR}/log.config ${STAGEDIR}${ETCDIR}/log.config.sample

.include <bsd.port.mk>
