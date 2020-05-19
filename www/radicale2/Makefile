# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	radicale2
PORTVERSION=	2.1.12
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
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.7.3:devel/py-dateutil@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flake8>=0:devel/py-flake8@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}isort>=0:devel/py-isort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-cov>=0:devel/py-pytest-cov@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}

USES=		python:3.3+ shebangfix
USE_PYTHON=	autoplist distutils
USERS=		radicale
GROUPS=		radicale
USE_RC_SUBR=	radicale
NO_ARCH=	yes
SHEBANG_FILES=	radicale.fcgi radicale.wsgi

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}radicale

SUB_LIST=	USERS="${USERS}" GROUPS="${GROUPS}" PYTHON_CMD="${PYTHON_CMD}"

post-patch:
	@${REINPLACE_CMD} 's,= /etc,= ${PREFIX}/etc,g' ${WRKSRC}/config
	@${REINPLACE_CMD} 's,~/.config/radicale,${DATADIR},g' ${WRKSRC}/config

post-install:
	${MKDIR} ${STAGEDIR}/${ETCDIR}
	${MKDIR} ${STAGEDIR}/${DATADIR}
	${MKDIR} ${STAGEDIR}/${WWWDIR}
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}/${ETCDIR}/config.sample
	${INSTALL_DATA} ${WRKSRC}/logging ${STAGEDIR}/${ETCDIR}/logging.sample
	${INSTALL_SCRIPT} ${WRKSRC}/radicale.fcgi ${STAGEDIR}${WWWDIR}/radicale.fcgi
	${INSTALL_SCRIPT} ${WRKSRC}/radicale.wsgi ${STAGEDIR}${WWWDIR}/radicale.wsgi

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
