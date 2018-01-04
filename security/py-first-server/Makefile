# $FreeBSD$

PORTNAME=	first-server
PORTVERSION=	0.0.3
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTVERSIONPREFIX=	v

CATEGORIES=	security

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Function Identification and Recovery Signature Tool

LICENSE=	GPLv2

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=1.3.8:databases/py-mysqlclient@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}django>=1.11.4:www/py-django@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}werkzeug>=0.11.11:www/py-werkzeug@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}httplib2>=0.9.2:www/py-httplib2@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oauth2client>=3.0.0:security/py-oauth2client@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.5.3:www/py-google-api-python-client@${FLAVOR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}capstone>=3.0.4:devel/py-capstone@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	vrtadmin
GH_PROJECT=	FIRST-server

USES=		python
USE_PYTHON=	flavors

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/server && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
