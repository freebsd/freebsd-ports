# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	keystone
PORTVERSION=	10.0.0
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	https://fossies.org/linux/misc/openstack/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Keystone

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.3:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}Paste>=0:www/py-paste \
		${PYTHON_PKGNAMEPREFIX}routes>=0:www/py-routes \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.9.6:databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.16.0:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.6:security/py-passlib \
		${PYTHON_PKGNAMEPREFIX}keystoneclient>=0:net/py-keystoneclient \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=0:devel/py-keystonemiddleware \
		${PYTHON_PKGNAMEPREFIX}oslo.cache>=1.5.0:devel/py-oslo.cache \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.2.0:devel/py-oslo.messaging \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=0:devel/py-oslo.db \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=1.14.0:devel/py-oslo.log \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.0.0:devel/py-oslo.middleware \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.9.0:devel/py-oslo.policy \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=0.6:security/py-oauthlib \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=0:security/py-pysaml2 \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.6.2:devel/py-dogpile.cache \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}pycadf>=0:devel/py-pycadf \
		${PYTHON_PKGNAMEPREFIX}msgpack-python>=0.4.0:devel/py-msgpack-python \
		${PYTHON_PKGNAMEPREFIX}osprofiler>=1.4.0:devel/py-osprofiler \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0:databases/py-sqlparse \
		${PYTHON_PKGNAMEPREFIX}python-editor>=0:devel/py-python-editor

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils noegginfo

USERS=		keystone
GROUPS=		keystone

post-patch:
	${REINPLACE_CMD} -e "s|/etc/keystone|${PREFIX}/etc/${PORTNAME}|g" \
		${WRKSRC}/doc/source/apache-httpd.rst \
		${WRKSRC}/doc/source/api_curl_examples.rst \
		${WRKSRC}/doc/source/configuration.rst \
		${WRKSRC}/doc/source/event_notifications.rst \
		${WRKSRC}/doc/source/federation/configure_federation.rst \
		${WRKSRC}/doc/source/http-api.rst \
		${WRKSRC}/doc/source/installing.rst \
		${WRKSRC}/doc/source/upgrading.rst \
		${WRKSRC}/etc/keystone.conf.sample \
		${WRKSRC}/keystone/tests/unit/test_ldap_tls_livetest.py \
		${WRKSRC}/keystone/conf/fernet_tokens.py \
		${WRKSRC}/keystone/conf/signing.py \
		${WRKSRC}/keystone/conf/saml.py \
		${WRKSRC}/keystone/conf/identity.py \
		${WRKSRC}/keystone/conf/constants.py \
		${WRKSRC}/keystone/conf/credential.py \
		${WRKSRC}/keystone/conf/federation.py \
		${WRKSRC}/keystone/common/profiler.py

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} -R ${WRKSRC}/etc/ ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
