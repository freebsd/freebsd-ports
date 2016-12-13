# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uwsgi
PORTVERSION=	2.0.14
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Developer-friendly WSGI server which uses uwsgi protocol

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python ssl
USE_PYTHON=	distutils
USE_RC_SUBR=	uwsgi

OPTIONS_DEFINE=	DEBUG JSON PCRE XML

DEBUG_VARS=	PYDISTUTILS_BUILDARGS+=--debug
JSON_LIB_DEPENDS=	libjansson.so:devel/jansson
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre
XML_LIB_DEPENDS=	libxml2.so:textproc/libxml2

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJSON}
O_JSON=		jansson
.else
O_JSON=		false
.endif

.if ${PORT_OPTIONS:MPCRE}
O_PCRE=		true
.else
O_PCRE=		false
.endif

.if ${PORT_OPTIONS:MXML}
O_XML=		libxml2
.else
O_XML=		false
.endif

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	${OPENSSL_LDFLAGS}
MAKE_ENV+=	CPUCOUNT=${MAKE_JOBS_NUMBER} UWSGI_EMBED_PLUGINS=cgi

PYSETUP=			uwsgiconfig.py
PYDISTUTILS_BUILD_TARGET=	--build
PYDISTUTILS_BUILDARGS=		--verbose

PLIST_FILES=	bin/uwsgi \
		%%PYTHON_SITELIBDIR%%/uwsgidecorators.py

post-patch:
	${REINPLACE_CMD} -e s#@JSON@#${O_JSON}# -e s#@XML@#${O_XML}# -e s#@PCRE@#${O_PCRE}# ${WRKSRC}/buildconf/base.ini

do-configure:
	@${DO_NADA}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/uwsgidecorators.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
