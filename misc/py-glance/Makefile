# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	glance
PORTVERSION=	16.0.1
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	https://tarballs.openstack.org/glance/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenStack Image Service

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Fails to build with recent versions of python, unmaintained
EXPIRATION_DATE=	2020-02-15

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.5.0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=1.0.10:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.18.2:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=2.3.1:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.7.1:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.11.0:databases/py-sqlalchemy-migrate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0.2.2:databases/py-sqlparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}alembic>=0.8.10:databases/py-alembic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.9.1:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.1.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.25.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.19.2:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}futurist>=1.2.0:devel/py-futurist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}taskflow>=2.16.0:devel/py-taskflow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=3.3.0:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=4.17.0:devel/py-keystonemiddleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsme>=0.8:devel/py-wsme@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0.7.1:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=2.0.2:www/py-paste@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.8.0:net/py-python-keystoneclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>=16.2.0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=4.27.0:devel/py-oslo.db@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.36.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.29.0:devel/py-oslo.messaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.31.0:devel/py-oslo.middleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.30.0:devel/py-oslo.policy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retrying>=1.2.3:devel/py-retrying@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osprofiler>=1.4.0:devel/py-osprofiler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}glance-store>=0.22.0:devel/py-glance-store@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.9:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cursive>=0.2.1:devel/py-cursive@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}monotonic>=0.6:devel/py-monotonic@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
USE_RC_SUBR=	glance-api glance-registry glance-scrubber

USERS=		glance
GROUPS=		glance

NO_ARCH=	yes
PORTDOCS=	*
SUB_LIST=	PYTHON_VER=${PYTHON_VER}

CONFLICTS_INSTALL=	py??-glance-*

OPTIONS_DEFINE=		DOCS
OPTIONS_GROUP=		MISC
OPTIONS_GROUP_MISC=	MEMCACHED MONGODB
OPTIONS_RADIO=		DB
OPTIONS_RADIO_DB=	MYSQL PGSQL

MEMCACHED_DESC=		memcached support
MONGODB_DESC=		MongoDB support (used for messaging services)
MYSQL_DESC=		MySQL/MariaDB support
PGSQL_DESC=		PostgreSQL support

DOCS_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sphinx>=1.6.2:textproc/py-sphinx@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}openstackdocstheme>=0:textproc/py-openstackdocstheme@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}xattr>=0:devel/py-xattr@${PY_FLAVOR} \
			${RUN_DEPENDS}
DOCS_VARS=		PYDISTUTILS_BUILD_TARGET+="build_sphinx -a -E"
MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=1.56:databases/py-python-memcached@${PY_FLAVOR}
MONGODB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=3.0.2:databases/pymongo@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymysql>=0:databases/py-pymysql@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}

MY_CONFFILES=	glance-api.conf glance-cache.conf glance-manage.conf \
		glance-registry.conf glance-scrubber.conf glance-api-paste.ini \
		glance-registry-paste.ini policy.json rootwrap.conf

MY_REGEX=	(/etc/)(ceph|glance|nova|pki|ssl)

post-extract:
	@(cd ${WRKSRC}/etc && for f in ${MY_CONFFILES} ; do ${MV} $${f} $${f}.sample; done)
	@(cd ${WRKSRC}/etc/metadefs && for f in *.json ; do ${MV} $${f} $${f}.sample; done)

post-patch:
	# Prevent the installation of files into ${ETCDIR} by distutils. We do it
	# manually in the post-install target
	@${REINPLACE_CMD} -e '/etc\//d' ${WRKSRC}/setup.cfg
	# Replace (hardcoded) paths of config, documentation and Python files
	@${GREP} -Rl -Ee '${MY_REGEX}' --null \
		${WRKSRC}/etc ${WRKSRC}/doc ${WRKSRC}/glance | \
			${XARGS} -0 ${REINPLACE_CMD} -i '' -Ee \
				"s,${MY_REGEX},${PREFIX}\1\2,g"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/metadefs
.for f in ${MY_CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/$f.sample ${STAGEDIR}${ETCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/metadefs/* ${STAGEDIR}${ETCDIR}/metadefs

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
		(cd ${WRKSRC}/doc/build/html && \
			${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
				"! -name .buildinfo -and ! -name objects.inv")

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 3700
BROKEN=		fails to build
.endif

.include <bsd.port.post.mk>
