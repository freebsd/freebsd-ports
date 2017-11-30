# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	cinder
PORTVERSION=	9.1.1
CATEGORIES=	misc python
MASTER_SITES=	https://fossies.org/linux/misc/openstack/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Storage Service (Cinder)

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator@${FLAVOR} \
		${PY_ENUM34} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0.3.2:devel/py-greenlet@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.7.5:www/py-httplib2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${FLAVOR} \
		${PY_IPADDRESS} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.10.0:devel/py-keystoneauth1@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=0:devel/py-keystonemiddleware@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.3:devel/py-lxml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=1.5.0:security/py-oauth2client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=0:devel/py-oslo.db@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=1.14.0:devel/py-oslo.log@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.2.0:devel/py-oslo.messaging@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.0.0:devel/py-oslo.middleware@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.9.0:devel/py-oslo.policy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.privsep>=1.9.0:devel/py-oslo.privsep@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.reports>=0.6.0:devel/py-oslo.reports@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.rootwrap>=5.0.0:devel/py-oslo.rootwrap@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=1.10.0:devel/py-oslo.service@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.versionedobjects>=1.13.0:devel/py-oslo.versionedobjects@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osprofiler>=1.4.0:devel/py-osprofiler@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.0:security/py-paramiko@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=0:www/py-paste@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6:security/py-pycrypto@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:devel/py-pyparsing@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-barbicanclient>=4.0.0:net/py-python-barbicanclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-glanceclient>=0:net/py-python-glanceclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=0:net/py-python-keystoneclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-novaclient>=0:net/py-python-novaclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-swiftclient>=2.2.0:databases/py-python-swiftclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}retrying>=0:devel/py-retrying@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=0:www/py-routes@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}taskflow>=1.26.0:devel/py-taskflow@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rtslib-fb>=0:devel/py-rtslib-fb@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.2.0:devel/py-simplejson@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.9.6:databases/py-sqlalchemy-migrate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.16.0:devel/py-stevedore@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.3:www/py-webob@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.vmware>=2.11.0:devel/py-oslo.vmware@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-brick>=1.6.1:devel/py-os-brick@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-win>=0.2.3:devel/py-os-win@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tooz>=1.28.0:devel/py-tooz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.4.1:www/py-google-api-python-client@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}castellan>=0.4.0:devel/py-castellan@${FLAVOR}

EXTRA_PATCHES=	${FILESDIR}/01-remotefs.patch:-p1 \
		${FILESDIR}/02-nfs.patch:-p1

NO_ARCH=	yes

USES=		python:2.7
USE_PYTHON=	autoplist distutils

USE_RC_SUBR=	cinder-api \
		cinder-scheduler \
		cinder-volume
USERS=		cinder
GROUPS=		cinder

post-extract:
	@(cd ${WRKSRC}/etc/cinder; ${MV} logging_sample.conf logging.conf.sample)
	@(cd ${WRKSRC}/etc/cinder; for f in *.conf; \
		do ${MV} $${f} $${f}.sample; done)
	# No need to ship this README becuase it tells how to generate sample config
	# file using tox, but we ship FreeBSD-friendly sample config already
	@${RM} ${WRKSRC}/etc/cinder/README-cinder.conf.sample

post-patch:
	${CP} ${FILESDIR}/cinder.conf.sample \
		${WRKSRC}/etc/cinder/cinder.conf.sample

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} -R ${WRKSRC}/etc/cinder/ ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
