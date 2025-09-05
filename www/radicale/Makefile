PORTNAME=	radicale
PORTVERSION=	3.5.5
CATEGORIES=	www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Python based CalDAV/CardDAV server
WWW=		https://radicale.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.md

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR} \
		${PY_SETUPTOOLS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.9.6:deskutils/py-vobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pika>=1.1.0:devel/py-pika@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.7.3:devel/py-python-dateutil@${PY_FLAVOR}

USES=		cpe python
USE_PYTHON=	autoplist pep517
USERS=		radicale
GROUPS=		radicale
USE_RC_SUBR=	radicale
NO_ARCH=	yes

OPTIONS_DEFINE=	ARGON2 BCRYPT LDAP
OPTIONS_DEFAULT=	ARGON2 BCRYPT LDAP

ARGON2_DESC=	argon2 support for password hashes
ARGON2_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argon2-cffi>0:security/py-argon2-cffi@${PY_FLAVOR}
BCRYPT_DESC=	bcrypt support for password hashes
BCRYPT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>0:security/py-bcrypt@${PY_FLAVOR}
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ldap3>0:net/py-ldap3@${PY_FLAVOR}

SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}" PYTHON_CMD="${PYTHON_CMD}"

post-patch:
	@${REINPLACE_CMD} 's,/etc/radicale,${ETCDIR},g' \
		${WRKSRC}/config \
		${WRKSRC}/radicale/config.py
	@${REINPLACE_CMD} 's,/etc/ssl,${ETCDIR},g' \
		${WRKSRC}/config \
		${WRKSRC}/radicale/config.py
	@${REINPLACE_CMD} 's,/var/lib/radicale,${DATADIR},g' \
		${WRKSRC}/config \
		${WRKSRC}/radicale/config.py

post-install:
	@${MKDIR} ${STAGEDIR}/${ETCDIR} ${STAGEDIR}/${DATADIR} ${STAGEDIR}/${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}/${ETCDIR}/config.sample
	${INSTALL_DATA} ${WRKSRC}/rights ${STAGEDIR}/${ETCDIR}/rights.sample
	${INSTALL_SCRIPT} ${WRKSRC}/radicale.wsgi ${STAGEDIR}${WWWDIR}/radicale.wsgi

.include <bsd.port.mk>
