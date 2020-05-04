# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	cinder
PORTVERSION=	12.0.10
PORTREVISION=	10
CATEGORIES=	misc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OpenStack Block Storage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.5.0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.18.2:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0.4.10:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.9.1:www/py-httplib2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=2.6.0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=3.3.0:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.4.1:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=1.5.0:security/py-oauth2client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=3.36.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osprofiler>=1.4.0:devel/py-osprofiler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.0.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=2.0.2:www/py-paste@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0.7.1:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>=3.2.2:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.1.0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-barbicanclient>=4.0.0:net/py-python-barbicanclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-glanceclient>=2.8.0:net/py-python-glanceclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.8.0:net/py-python-keystoneclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-swiftclient>=3.2.0:databases/py-python-swiftclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.14.2:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retrying>=1.2.3:devel/py-retrying@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=2.3.1:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtslib-fb>=2.1.43:devel/py-rtslib-fb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=3.5.1:devel/py-simplejson@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy12>=1.0.10:databases/py-sqlalchemy12@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.11.0:databases/py-sqlalchemy-migrate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.20.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}suds-jurko>=0.6:net/py-suds-jurko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.7.1:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-brick>=2.2.0:devel/py-os-brick@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tooz>=1.58.0:devel/py-tooz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.4.2:www/py-google-api-python-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=1.9:security/py-cryptography@${PY_FLAVOR} \
		${PY_IPADDRESS} \
		${PY_ENUM34}

USES=		python
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes
USE_RC_SUBR=	cinder-api cinder-scheduler cinder-volume

USERS=		cinder
GROUPS=		cinder

SUB_LIST=	PYTHON_VER=${PYTHON_VER}

CONFLICTS_INSTALL=	py??-cinder-*

PORTSCOUT=	skipv:2015.1.4

OPTIONS_DEFINE=	MEMCACHED MONGODB
OPTIONS_RADIO=	DB
OPTIONS_RADIO_DB=	MYSQL PGSQL
MEMCACHED_DESC=	Memcached support
MONGODB_DESC=	MongoDB support (used for messaging services)
MYSQL_DESC=	MySQL/MariaDB support
PGSQL_DESC=	PostgreSQL support

MEMCACHED_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-memcached>=1.56:databases/py-python-memcached@${PY_FLAVOR}
MONGODB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymongo>=3.0.2:databases/pymongo@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pymysql>=0:databases/py-pymysql@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=0:databases/py-psycopg2@${PY_FLAVOR}

MY_REGEX=	(/etc/)(ceph|nova|pki|ssl)

post-patch:
	# Prevent the installation of files into ${ETCDIR} by distutils. We do it
	# manually in the post-install target
	@${REINPLACE_CMD} -e '/etc\//d' ${WRKSRC}/setup.cfg
	${CP} ${FILESDIR}/cinder.conf.sample ${WRKSRC}/etc/cinder/cinder.conf
	# Replace (hardcoded) paths of config, documentation and Python files
	@${GREP} -Rl -Ee '${MY_REGEX}' --null \
		${WRKSRC}/etc ${WRKSRC}/doc ${WRKSRC}/cinder | \
			${XARGS} -0 ${REINPLACE_CMD} -i '' -Ee \
				"s,${MY_REGEX},${PREFIX}\1\2,g"

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}/rootwrap.d
.for f in api-paste.ini cinder.conf rootwrap.conf rootwrap.d/volume.filters
	${INSTALL_DATA} ${WRKSRC}/etc/cinder/$f ${STAGEDIR}${ETCDIR}/$f.sample
.endfor

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}castellan1>=0.16.0:devel/py-castellan1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware8>=4.17.0:devel/py-keystonemiddleware8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-win4>=3.0.0:devel/py-os-win4@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency3>=3.25.0:devel/py-oslo.concurrency3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config7>=5.1.0:devel/py-oslo.config7@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context2>=2.19.2:devel/py-oslo.context2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.db6>=4.27.0:devel/py-oslo.db6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging10>=5.29.0:devel/py-oslo.messaging10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware3>=3.31.0:devel/py-oslo.middleware3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.policy2>=1.30.0:devel/py-oslo.policy2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.privsep1>=1.23.0:devel/py-oslo.privsep1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.reports1>=1.18.0:devel/py-oslo.reports1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.rootwrap5>=5.8.0:devel/py-oslo.rootwrap5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.service1>=1.24.0:devel/py-oslo.service1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.versionedobjects1>=1.31.2:devel/py-oslo.versionedobjects1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.vmware2>=2.17.0:devel/py-oslo.vmware2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-novaclient16>=9.1.0:net/py-python-novaclient16@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}taskflow3>=2.16.0:devel/py-taskflow3@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}castellan>=0.16.0:devel/py-castellan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=4.17.0:devel/py-keystonemiddleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-win>=3.0.0:devel/py-os-win@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.25.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.1.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.19.2:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=4.27.0:devel/py-oslo.db@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.29.0:devel/py-oslo.messaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.31.0:devel/py-oslo.middleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.30.0:devel/py-oslo.policy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.privsep>=1.23.0:devel/py-oslo.privsep@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.reports>=1.18.0:devel/py-oslo.reports@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.rootwrap>=5.8.0:devel/py-oslo.rootwrap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=1.24.0:devel/py-oslo.service@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.versionedobjects>=1.31.2:devel/py-oslo.versionedobjects@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.vmware>=2.17.0:devel/py-oslo.vmware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-novaclient>=9.1.0:net/py-python-novaclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}taskflow>=2.16.0:devel/py-taskflow@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
