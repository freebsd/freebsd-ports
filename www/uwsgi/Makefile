# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uwsgi
PORTVERSION=	2.0.13
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Developer-friendly WSGI server which uses uwsgi protocol

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python
USE_PYTHON=	distutils
USE_RC_SUBR=	uwsgi

OPTIONS_DEFINE=	DEBUG

DEBUG_VARS=	PYDISTUTILS_BUILDARGS+=--debug

LDFLAGS+=	"-L${LOCALBASE}/lib"
MAKE_ENV+=	CPUCOUNT=${MAKE_JOBS_NUMBER} UWSGI_EMBED_PLUGINS=cgi

PYSETUP=			uwsgiconfig.py
PYDISTUTILS_BUILD_TARGET=	--build
PYDISTUTILS_BUILDARGS=		--verbose

PLIST_FILES=	bin/uwsgi \
		%%PYTHON_SITELIBDIR%%/uwsgidecorators.py

do-configure:
	@${DO_NADA}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/uwsgidecorators.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
