# Created by: Daniel Gerzo <danger@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uwsgi
PORTVERSION=	2.0.15
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Developer-friendly WSGI server which uses uwsgi protocol

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig python ssl
USE_PYTHON=	distutils
USE_RC_SUBR=	uwsgi

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	${OPENSSL_LDFLAGS}
MAKE_ENV+=	CPUCOUNT=${MAKE_JOBS_NUMBER} UWSGI_EMBED_PLUGINS=cgi

PYSETUP=			uwsgiconfig.py
PYDISTUTILS_BUILD_TARGET=	--build
PYDISTUTILS_BUILDARGS=		--verbose

USERS=		uwsgi
GROUPS=		uwsgi

PLIST_FILES=	bin/uwsgi \
		%%PYTHON_SITELIBDIR%%/uwsgidecorators.py

OPTIONS_DEFINE=	DEBUG JSON PCRE XML

DEBUG_VARS=		PYDISTUTILS_BUILDARGS+=--debug

JSON_VARS=		BUILDCONF_JSON=jansson
JSON_LIB_DEPENDS=	libjansson.so:devel/jansson

PCRE_VARS=		BUILDCONF_PCRE=true
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

XML_VARS=		BUILDCONF_XML=libxml2
XML_LIB_DEPENDS=	libxml2.so:textproc/libxml2

LIB_DEPENDS+=	libjansson.so:devel/jansson libpcre.so:devel/pcre libxml2.so:textproc/libxml2

.include <bsd.port.options.mk>

post-patch:
.for var in JSON PCRE XML
	@${REINPLACE_CMD} -e '/^${var:tl} =/ s|= .*|= ${BUILDCONF_${var}:Ufalse}|' ${WRKSRC}/buildconf/base.ini
.endfor

do-configure:
	@${DO_NADA}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/uwsgidecorators.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
