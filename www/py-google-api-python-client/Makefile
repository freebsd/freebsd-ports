# New ports collection makefile for:	google-api-python-client
# Date created:		2011-04-16
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	google-api-python-client
#PORTVERSION=
#PORTREVISION=	0
DISTVERSION=	1.0c2
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES+=	${PORTNAME}-${DISTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google API Client Library for Python

LICENSE=	AL2

RUN_DEPENDS=	${PKGNAMEPREFIX}gflags>=1.4:${PORTSDIR}/devel/py-gflags \
		${PKGNAMEPREFIX}httplib2>=0.6.0:${PORTSDIR}/www/py-httplib2 \
		${PKGNAMEPREFIX}oauth2>=1.5.167:${PORTSDIR}/net/py-oauth2

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS DJANGO EXAMPLES GAE WEBTEST

DJANGO_DESC=	Use the library with Django
GAE_DESC=	Use the library with Google App Engine
WEBTEST_DESC=	Use WebTest helper to test WSGI apps (Python 2.6+)

.include <bsd.port.options.mk>

PYDISTUTILS_PKGVERSION=	${DISTVERSION}

.if ${PORT_OPTIONS:MEXAMPLES}
FIND_FILES=	${WRKDIR}/samples
FIND_FILES_BAK=	${WRKDIR}/samples
.endif
FIND_FILES+=	${WRKSRC} -type f -and \( -name "*.py" -or -name "enable-app-engine-project" \) -print0
FIND_FILES_BAK+=	${WRKSRC} -type f -name "*.bak"

XARGS_ARGS=	-0

REINPLACE_ARGS=	-i.bak -e 's,/usr/bin/env python,&${PYTHON_VER},' \
		-e 's,/usr/bin/python.*,${PYTHON_CMD},' \
		-e 's,../google_appengine,${LOCALBASE}/share/google-appengine,1' \
		-e "s,'samples/oauth2','${EXAMPLESDIR}',1"

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

.if ${PORT_OPTIONS:MEXAMPLES}
DISTFILES+=	${PORTNAME}-samples-${DISTVERSION}.tar.gz
.endif

.if ${PORT_OPTIONS:MGAE}
RUN_DEPENDS+=	google-appengine>=1.4.3:${PORTSDIR}/www/google-appengine
.endif

.if ${PORT_OPTIONS:MDJANGO}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}django>=1.3:${PORTSDIR}/www/py-django
.endif

post-patch:
	${FIND} ${FIND_FILES} | ${XARGS} ${XARGS_ARGS} ${REINPLACE_CMD}
	@${FIND} ${FIND_FILES_BAK} -delete

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}/FAQ
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/runsamples.py ${EXAMPLESDIR}/runsamples.py
	cd ${WRKDIR}/samples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

# www/py-WebTest depends on www/py-webob, which runs only with Python 2.6+
.if ${PORT_OPTIONS:MWEBTEST} && ${PYTHON_VER} >= 2.6
RUN_DEPENDS+=	${PKGNAMEPREFIX}WebTest>=1.3.3:${PORTSDIR}/www/py-WebTest \
		${PKGNAMEPREFIX}openssl>=0.13:${PORTSDIR}/security/py-openssl
.endif

.if ${PYTHON_VER} <= 2.5
RUN_DEPENDS+=	${PKGNAMEPREFIX}simplejson>=2.5.0:${PORTSDIR}/devel/py-simplejson
.endif

.include <bsd.port.post.mk>
