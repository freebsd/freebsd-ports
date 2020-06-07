# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	radicale
PORTVERSION=	3.0.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Radicale-${PORTVERSION}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Python based CalDAV/CardDAV server

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bcrypt>=0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>=0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.9.6:deskutils/py-vobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.7.3:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedxml>0:devel/py-defusedxml@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}waitress>=0:www/py-waitress@${PY_FLAVOR}

USES=		python:3.3+ shebangfix
USE_PYTHON=	autoplist distutils
USERS=		radicale
GROUPS=		radicale
USE_RC_SUBR=	radicale
NO_ARCH=	yes
SHEBANG_FILES=	radicale.fcgi radicale.wsgi

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
	${INSTALL_SCRIPT} ${WRKSRC}/radicale.fcgi ${STAGEDIR}${WWWDIR}/radicale.fcgi
	${INSTALL_SCRIPT} ${WRKSRC}/radicale.wsgi ${STAGEDIR}${WWWDIR}/radicale.wsgi

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
