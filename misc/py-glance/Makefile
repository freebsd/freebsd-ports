# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	glance
PORTVERSION=	13.0.0
PORTREVISION=	1
CATEGORIES=	misc python
MASTER_SITES=	https://fossies.org/linux/misc/openstack/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Image Service

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr

RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}routes>=0:www/py-routes \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.3:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.9.6:databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}httplib2>=0.7.5:www/py-httplib2 \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=1.10.0:devel/py-oslo.service \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.16.0:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}futurist>=0:devel/py-futurist \
		${PYTHON_PKGNAMEPREFIX}taskflow>=1.26.0:devel/py-taskflow \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.10.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=0:devel/py-keystonemiddleware \
		${PYTHON_PKGNAMEPREFIX}wsme>=0.8:devel/py-wsme \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable \
		${PYTHON_PKGNAMEPREFIX}Paste>=0:www/py-paste \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}keystoneclient>=0:net/py-keystoneclient \
		${PYTHON_PKGNAMEPREFIX}openssl>=0.14:security/py-openssl \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=0:devel/py-oslo.db \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=1.14.0:devel/py-oslo.log \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.2.0:devel/py-oslo.messaging \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.0.0:devel/py-oslo.middleware \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.9.0:devel/py-oslo.policy \
		${PYTHON_PKGNAMEPREFIX}retrying>=0:devel/py-retrying \
		${PYTHON_PKGNAMEPREFIX}osprofiler>=1.4.0:devel/py-osprofiler \
		${PYTHON_PKGNAMEPREFIX}glance-store>=0.18.0:devel/py-glance-store \
		${PYTHON_PKGNAMEPREFIX}semantic_version>=2.3.1:devel/py-semantic_version \
		${PYTHON_PKGNAMEPREFIX}debtcollector>=1.2.0:devel/py-debtcollector \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}cursive>=0.1.1:devel/py-cursive \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601 \
		${PYTHON_PKGNAMEPREFIX}monotonic>=0.6:devel/py-monotonic \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0:databases/py-sqlparse

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils noegginfo

USE_RC_SUBR=	glance-api glance-registry glance-scrubber glance-glare
USERS=		glance
GROUPS=		glance

post-extract:
	@(cd ${WRKSRC}/etc; for f in *.conf; do ${MV} $${f} $${f}.sample; done)

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${CP} -R ${WRKSRC}/etc/ ${STAGEDIR}${PREFIX}/etc/${PORTNAME}

.include <bsd.port.mk>
