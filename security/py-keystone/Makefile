# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	keystone
PORTVERSION=	10.0.0
PORTREVISION=	4
CATEGORIES=	security python
MASTER_SITES=	https://fossies.org/linux/misc/openstack/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Keystone

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.3:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=0:www/py-paste@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=0:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.9.6:databases/py-sqlalchemy-migrate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.16.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=1.6:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=0:net/py-python-keystoneclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=0:devel/py-keystonemiddleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.cache>=1.5.0:devel/py-oslo.cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.2.0:devel/py-oslo.messaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=0:devel/py-oslo.db@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=1.14.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.0.0:devel/py-oslo.middleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.9.0:devel/py-oslo.policy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oauthlib>=0.6:security/py-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=0:security/py-pysaml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dogpile.cache>=0.6.2:devel/py-dogpile.cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycadf>=0:devel/py-pycadf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}msgpack>=0.4.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osprofiler>=1.4.0:devel/py-osprofiler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0:databases/py-sqlparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-editor>=0:devel/py-python-editor@${PY_FLAVOR}

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''

USES=		python
USE_PYTHON=	autoplist distutils noegginfo

USERS=		keystone
GROUPS=		keystone

post-patch:
	@${REINPLACE_CMD} -e 's|msgpack-python|msgpack|' ${WRKSRC}/requirements.txt ${WRKSRC}/keystone.egg-info/requires.txt
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
