PORTNAME=	uwsgi
PORTVERSION=	2.0.30
CATEGORIES=	www python
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Developer-friendly WSGI server which uses uwsgi protocol
WWW=		https://projects.unbit.it/uwsgi/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe pkgconfig python
USE_GITHUB=	yes
GH_ACCOUNT=	unbit
USE_PYTHON=	distutils concurrent
USE_RC_SUBR=	uwsgi
CPE_VENDOR=	unbit

MAKE_ENV+=	CPUCOUNT=${MAKE_JOBS_NUMBER} UWSGI_EMBED_PLUGINS=cgi

PYSETUP=			uwsgiconfig.py
PYDISTUTILS_BUILD_TARGET=	--build
PYDISTUTILS_BUILDARGS=		--verbose

USERS=		uwsgi
GROUPS=		uwsgi

PLIST_FILES=	bin/uwsgi \
		${PYTHON_SITELIBDIR}/uwsgidecorators.py

SUB_LIST=	PYTHON_VER=${PYTHON_VER}

OPTIONS_DEFINE=		DEBUG JSON PCRE XML SSL
OPTIONS_DEFAULT=	SSL

OPTIONS_GROUP=		PLG
OPTIONS_GROUP_PLG=	COROAE LOGPIPE PSGI

PLG_DESC=		Enable plugins
COROAE_DESC=		Coro::AnyEvent support
LOGPIPE_DESC=		Pipe logger support
PSGI_DESC=		PSGI embedded plugin

COROAE_BUILD_DEPENDS=	p5-Coro>=0:devel/p5-Coro
COROAE_IMPLIES=		PSGI

DEBUG_VARS=		PYDISTUTILS_BUILDARGS+=--debug

JSON_VARS=		BUILDCONF_JSON=jansson
JSON_LIB_DEPENDS=	libjansson.so:devel/jansson

PCRE_VARS=		BUILDCONF_PCRE=true
PCRE_LIB_DEPENDS=	libpcre.so:devel/pcre

PSGI_USES=		perl5

XML_VARS=		BUILDCONF_XML=libxml2
XML_LIB_DEPENDS=	libxml2.so:textproc/libxml2

SSL_VARS=		BUILDCONF_SSL=true
SSL_USES=		ssl
SSL_CFLAGS=		-I${OPENSSLINC}
SSL_LDFLAGS=		${OPENSSL_LDFLAGS}

post-patch:
.for var in JSON PCRE XML SSL
	@${REINPLACE_CMD} -e '/^${var:tl} =/ s|= .*|= ${BUILDCONF_${var}:Ufalse}|' ${WRKSRC}/buildconf/base.ini
.endfor

.for plugin in COROAE LOGPIPE PSGI
post-patch-${plugin}-on:
	@${REINPLACE_CMD} -e 's/%(main_plugin)s,/& ${plugin:tl},/' \
		${WRKSRC}/buildconf/base.ini
.endfor

do-configure:
	@${DO_NADA}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/uwsgidecorators.py ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
