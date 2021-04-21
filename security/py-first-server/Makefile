PORTNAME=	first-server
PORTVERSION=	0.0.7
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	security
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Function Identification and Recovery Signature Tool

LICENSE=	GPLv2

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}capstone>0:devel/py-capstone@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=1.3.8:databases/py-mysqlclient@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}django32>=3.0.2:www/py-django32@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}werkzeug>=0.11.11:www/py-werkzeug@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}httplib2>=0.9.2:www/py-httplib2@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oauth2client>=3.0.0:security/py-oauth2client@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.5.3:www/py-google-api-python-client@${PY_FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}capstone>=3.0.4:devel/py-capstone@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	vrtadmin
GH_PROJECT=	FIRST-server

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/server && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
