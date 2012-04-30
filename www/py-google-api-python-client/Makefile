# New ports collection makefile for:	google-api-python-client
# Date created:		2011-04-16
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	google-api-python-client
#PORTVERSION=
#PORTREVISION=	0
DISTVERSION=	1.0beta8
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google API Client Library for Python

LICENSE=	AL2

BUILD_DEPENDS=	${PKGNAMEPREFIX}gflags>=1.4:${PORTSDIR}/devel/py-gflags \
		${PKGNAMEPREFIX}httplib2>=0.6.0:${PORTSDIR}/www/py-httplib2 \
		${PKGNAMEPREFIX}oauth2>=1.5.167:${PORTSDIR}/net/py-oauth2 \
		${PKGNAMEPREFIX}simplejson>=2.5.0:${PORTSDIR}/devel/py-simplejson
RUN_DEPENDS=	${PKGNAMEPREFIX}gflags>=1.4:${PORTSDIR}/devel/py-gflags \
		${PKGNAMEPREFIX}httplib2>=0.6.0:${PORTSDIR}/www/py-httplib2 \
		${PKGNAMEPREFIX}oauth2>=1.5.167:${PORTSDIR}/net/py-oauth2 \
		${PKGNAMEPREFIX}simplejson>=2.5.0:${PORTSDIR}/devel/py-simplejson \
		${PKGNAMEPREFIX}WebTest>=1.3.3:${PORTSDIR}/www/py-WebTest

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

OPTIONS=	GAE	"Use the library with Google App Engine" off \
		DJANGO	"Use the library with Django" off

PYDISTUTILS_PKGVERSION=	${DISTVERSION}

FIND_FILES=	${WRKSRC} -type f -and \( -name "*.py" -or -name "enable-app-engine-project" \) -print0
FIND_FILES_BAK=	${WRKSRC} -type f -name "*.bak"

XARGS_ARGS=	-0

REINPLACE_ARGS=	-i.bak -e 's,/usr/bin/env python,&${PYTHON_VER},' \
		-e 's,/usr/bin/python.*,${PYTHON_CMD},'

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	${FIND} ${FIND_FILES} | ${XARGS} ${XARGS_ARGS} ${REINPLACE_CMD}
	@${FIND} ${FIND_FILES_BAK} -delete

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_GAE)
RUN_DEPENDS+=	google-appengine>=1.4.3:${PORTSDIR}/www/google-appengine
.endif

.if defined(WITH_DJANGO)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}django>=1.3:${PORTSDIR}/www/py-django
.endif

.include <bsd.port.post.mk>
