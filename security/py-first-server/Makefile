# $FreeBSD$

PORTNAME=	first-server
PORTVERSION=	0.0.1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTVERSIONPREFIX=	v

CATEGORIES=	security

MAINTAINER=	dvl@FreeBSD.org
COMMENT=	Function Identification and Recovery Signature Tool

LICENSE=	GPLv2

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=1.3.8:databases/py-mysqlclient
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mongoengine>=0.10.0:devel/py-mongoengine
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}django>=1.10.2:www/py-django
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}werkzeug>=0.11.11:www/py-werkzeug
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}httplib2>=0.9.2:www/py-httplib2
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oauth2client>=3.0.0:security/py-oauth2client
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}google-api-python-client>=1.5.3:www/py-google-api-python-client
RUN_DEPENDS+=	distorm>=0:devel/distorm

USE_GITHUB=	yes
GH_ACCOUNT=	vrtadmin
GH_PROJECT=	FIRST-server

USES=		python

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}/server && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
