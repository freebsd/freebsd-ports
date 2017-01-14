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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}enum34>=0:devel/py-enum34 \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0.3.2:devel/py-greenlet \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.7.5:www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601 \
		${PYTHON_PKGNAMEPREFIX}ipaddress>=1.0.7:net/py-ipaddress \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.10.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=0:devel/py-keystonemiddleware \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.3:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}oauth2client>=1.5.0:security/py-oauth2client \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=0:devel/py-oslo.db \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=1.14.0:devel/py-oslo.log \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.2.0:devel/py-oslo.messaging \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.0.0:devel/py-oslo.middleware \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.9.0:devel/py-oslo.policy \
		${PYTHON_PKGNAMEPREFIX}oslo.privsep>=1.9.0:devel/py-oslo.privsep \
		${PYTHON_PKGNAMEPREFIX}oslo.reports>=0.6.0:devel/py-oslo.reports \
		${PYTHON_PKGNAMEPREFIX}oslo.rootwrap>=5.0.0:devel/py-oslo.rootwrap \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=1.10.0:devel/py-oslo.service \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oslo.versionedobjects>=1.13.0:devel/py-oslo.versionedobjects \
		${PYTHON_PKGNAMEPREFIX}osprofiler>=1.4.0:devel/py-osprofiler \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.0:security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}Paste>=0:www/py-paste \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=2.0.1:devel/py-pyparsing \
		${PYTHON_PKGNAMEPREFIX}python-barbicanclient>=4.0.0:net/py-python-barbicanclient \
		${PYTHON_PKGNAMEPREFIX}python-glanceclient>=0:net/py-python-glanceclient \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=0:net/py-python-keystoneclient \
		${PYTHON_PKGNAMEPREFIX}python-novaclient>=0:net/py-python-novaclient \
		${PYTHON_PKGNAMEPREFIX}python-swiftclient>=2.2.0:databases/py-python-swiftclient \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}retrying>=0:devel/py-retrying \
		${PYTHON_PKGNAMEPREFIX}routes>=0:www/py-routes \
		${PYTHON_PKGNAMEPREFIX}taskflow>=1.26.0:devel/py-taskflow \
		${PYTHON_PKGNAMEPREFIX}rtslib-fb>=0:devel/py-rtslib-fb \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.2.0:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.9.6:databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.16.0:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.3:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.vmware>=2.11.0:devel/py-oslo.vmware \
		${PYTHON_PKGNAMEPREFIX}os-brick>=1.6.1:devel/py-os-brick \
		${PYTHON_PKGNAMEPREFIX}os-win>=0.2.3:devel/py-os-win \
		${PYTHON_PKGNAMEPREFIX}tooz>=1.28.0:devel/py-tooz \
		${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.4.1:www/py-google-api-python-client \
		${PYTHON_PKGNAMEPREFIX}castellan>=0.4.0:devel/py-castellan

EXTRA_PATCHES=	${FILESDIR}/01-remotefs.patch:-p1 \
		${FILESDIR}/02-nfs.patch:-p1

NO_ARCH=	yes

USES=		python
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
