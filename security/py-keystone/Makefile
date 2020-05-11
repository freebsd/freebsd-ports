# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	keystone
PORTVERSION=	13.0.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	https://tarballs.openstack.org/keystone/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Identity

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		fails to build

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.7.1:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=2.0.2:www/py-paste@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=2.3.1:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.9:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=1.0.10:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.11.0:databases/py-sqlalchemy-migrate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.7.0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.8.0:net/py-python-keystoneclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=4.17.0:devel/py-keystonemiddleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>=3.1.3:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scrypt>=0.8.0:security/py-scrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.cache>=1.26.0:devel/py-oslo.cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.25.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.1.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.19.2:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.29.0:devel/py-oslo.messaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=4.27.0:devel/py-oslo.db@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.36.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.31.0:devel/py-oslo.middleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.30.0:devel/py-oslo.policy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=0.6.0:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=4.0.2:security/py-pysaml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.6.2:devel/py-dogpile.cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycadf>=1.1.0:devel/py-pycadf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osprofiler>=1.4.0:devel/py-osprofiler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6:devel/py-pytz@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

USERS=		keystone
GROUPS=		keystone

PORTDOCS=	*
PORTEXAMPLES=	examples/* httpd/* playbooks/*

SUB_FILES=	pkg-message
SUB_LIST=	EXAMPLESDIR=${EXAMPLESDIR} PREFIX=${PREFIX}

CONFLICTS_INSTALL=	py??-keystone-*

PORTSCOUT=	skipv:2015.1.3,2015.1.4

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_GROUP=		MISC
OPTIONS_GROUP_MISC=	LDAP MEMCACHED MONGODB
OPTIONS_RADIO=		DB
OPTIONS_RADIO_DB=	MYSQL PGSQL

LDAP_DESC=		LDAP support
MEMCACHED_DESC=		memcached support
MONGODB_DESC=		MongoDB support (used for messaging services)
MYSQL_DESC=		MySQL/MariaDB support
PGSQL_DESC=		PostgreSQL support

DOCS_BUILD_DEPENDS=	${PY_SPHINX} \
			${PYTHON_PKGNAMEPREFIX}openstackdocstheme>=1.18.1:textproc/py-openstackdocstheme@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}reno>=2.5.0:textproc/py-reno@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ldap>=2.4.20:net/py-ldap@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}testtools>=2.2.0:devel/py-testtools@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}os-api-ref>=1.4.0:textproc/py-os-api-ref@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}WebTest>=2.0.27:www/py-WebTest@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}freezegun>=0.3.6:devel/py-freezegun@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}flake8-docstrings>=0.2.1:devel/py-flake8-docstrings@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oslotest>=3.2.0:devel/py-oslotest@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oslo.db>=4.27.0:devel/py-oslo.db@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}lxml>=3.4.1:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ldappool>=2.0.0:net/py-ldappool@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}osprofiler>=0:devel/py-osprofiler@${PY_FLAVOR} \
			${RUN_DEPENDS}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap>=2.4.20:net/py-ldap@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}ldappool>=2.0.0:net/py-ldappool@${PY_FLAVOR}
MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=1.56:databases/py-python-memcached@${PY_FLAVOR}
MONGODB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=3.0.2:databases/pymongo@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymysql>=0:databases/py-pymysql@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -Ee 's|(pysaml2)<4.0.3,|\1|' ${WRKSRC}/requirements.txt
	@${GREP} -Rl -e '/etc/keystone/' --null \
		${WRKSRC}/etc ${WRKSRC}/doc ${WRKSRC}/keystone | \
			${XARGS} -0 ${REINPLACE_CMD} -i '' -Ee \
				"s|/etc/keystone/|${ETCDIR}/|g"

	@${GREP} -Rl -e '/var/log/apache2/' --null \
		${WRKSRC}/doc ${WRKSRC}/httpd | \
			${XARGS} -0 ${REINPLACE_CMD} -i '' -Ee \
				"s|(/var/log)/apache2|\1|g"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC}/etc && for f in *; do \
		${INSTALL_DATA} $${f} ${STAGEDIR}${ETCDIR}; done)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc/build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
			"! -name .buildinfo -and ! -name objects.inv")

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for dir in ${PORTEXAMPLES:C/\/\*//}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${dir}
	(cd ${WRKSRC}/${dir} && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/${dir})
.endfor

.include <bsd.port.mk>
