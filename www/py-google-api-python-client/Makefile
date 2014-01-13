# $FreeBSD$

PORTNAME=	google-api-python-client
PORTVERSION=	1.1
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Google API Client Library for Python

LICENSE=	APACHE20

RUN_DEPENDS=	${PKGNAMEPREFIX}gflags>=1.4:${PORTSDIR}/devel/py-gflags \
		${PKGNAMEPREFIX}httplib2>=0.6.0:${PORTSDIR}/www/py-httplib2 \
		${PKGNAMEPREFIX}oauth2>=1.5.167:${PORTSDIR}/net/py-oauth2

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

# bypass infrastructure bug
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DOCS DJANGO EXAMPLES GAE WEBTEST

DJANGO_DESC=	Use the library with Django
GAE_DESC=	Use the library with Google App Engine
WEBTEST_DESC=	Use WebTest helper to test WSGI apps (Python 2.6+)

NO_STAGE=	yes
.include <bsd.port.options.mk>

PYDISTUTILS_PKGVERSION=	${DISTVERSION}

.if ${PORT_OPTIONS:MEXAMPLES}
FIND_FILES=	${WRKDIR}/samples
FIND_FILES_BAK=	${WRKDIR}/samples
.endif
FIND_FILES+=	${WRKSRC} -type f -and \( -name "*.py" -or -name "enable-app-engine-project" \) -print0
FIND_FILES_BAK+=	${WRKSRC} -type f -name "*.bak"

REINPLACE_ARGS=	-e 's,/usr/bin/env python,&${PYTHON_VER},' \
		-e 's,/usr/bin/python.*,${PYTHON_CMD},' \
		-e 's,../google_appengine,${LOCALBASE}/share/google-appengine,1' \
		-e "s,'samples/oauth2','${EXAMPLESDIR}',1" -i.bak

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
	${FIND} ${FIND_FILES} | ${XARGS} -0 ${REINPLACE_CMD}
	@${FIND} ${FIND_FILES_BAK} -delete

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}/FAQ
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKDIR}/samples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.if ${PORT_OPTIONS:MWEBTEST}
RUN_DEPENDS+=	${PKGNAMEPREFIX}WebTest>=1.3.3:${PORTSDIR}/www/py-WebTest \
		${PKGNAMEPREFIX}openssl>=0.13:${PORTSDIR}/security/py-openssl
.endif

.include <bsd.port.mk>
