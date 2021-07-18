# Created by: Nicola Vitale <nivit@FreeBSD.org>

PORTNAME=	vertx
PORTVERSION=	2.1.1
PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	http://dl.bintray.com/vertx/downloads/
DISTNAME=	vert.x-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Effortless asynchronous application development for the modern web

LICENSE=	APACHE20

RUN_DEPENDS=	bash:shells/bash

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JAVA_OS=	native
JAVA_RUN=	yes

PLIST_SUB=	VERTXVER=${PORTVERSION}

REINPLACE_ARGS=	-i ''

SED_APPEND_ARGS=	${nl}JAVA_HOME=${JAVA_HOME}
SHEBANG_FILES=	bin/vertx

USE_JAVA=	yes
USES=	shebangfix

VERTX_CMD=	${WRKSRC}/bin/vertx
VERTX_DIST=	client conf lib

OPTIONS_DEFINE=	CLOJURE DOCS DYNJS GROOVY JYTHON JRUBY PHP RHINO SCALA
OPTIONS_SUB=	yes

CLOJURE_DESC=	Use Clojure to write verticles
DYNJS_DESC=	Use DynJS to write verticles
GROOVY_DESC=	Use Groovy to write verticles
JYTHON_DESC=	Use Python to write verticles
JRUBY_DESC=	Use Ruby to write verticles
PHP_DESC=	Use PHP to write verticles (experimental)
RHINO_DESC=	Use Rhino to write verticles
SCALA_DESC=	Use Scala to write verticles

JYTHON_RUN_DEPENDS=	jython:lang/jython
JRUBY_RUN_DEPENDS=	jruby:lang/jruby

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLOJURE}
VERTX_MODULES=	clojure
.endif

.if ${PORT_OPTIONS:MDYNJS}
VERTX_MODULES+=	dynjs
.endif

.if ${PORT_OPTIONS:MGROOVY}
VERTX_MODULES+=	groovy
.endif

.if ${PORT_OPTIONS:MJYTHON}
SED_APPEND_ARGS+=	\${nl}JYTHON_HOME=${LOCALBASE}/lib/jython
VERTX_MODULES+=	jython
.endif

.if ${PORT_OPTIONS:MJRUBY}

SED_APPEND_ARGS+=	\${nl}JRUBY_HOME=${LOCALBASE}/share/jruby
VERTX_MODULES+=	ruby
.endif

.if ${PORT_OPTIONS:MPHP}
VERTX_MODULES+=	php
.endif

.if ${PORT_OPTIONS:MRHINO}
VERTX_MODULES+=	rhino
.endif

.if ${PORT_OPTIONS:MSCALA}
VERTX_MODULES+=	scala
.endif

nl=	${.newline}

.if !empty(VERTX_MODULES)
MAKE_ENV=	VERTX_MODS=${WRKSRC}
PLIST_SUB+=	SYSMODS=""
VERTX_DIST+=	sys-mods

do-build:
	@(cd ${VERTX_MODS} && \
	for mod in $$(${CUT} -s -d = -f 2 ${WRKSRC}/conf/langs.properties | \
	${CUT} -s -d : -f 1 | ${EGREP} -i -e '(${VERTX_MODULES:ts|})'); do \
	${VERTX_CMD} install $${mod}; \
	done;)
.else
PLIST_SUB+=	SYSMODS="@comment "

do-build:
	@${DO_NADA}
.endif

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name "*.bat" -o -name "*.orig" \) -delete
	@${REINPLACE_CMD} -E -e '/APP_BASE_NAME=/a \${SED_APPEND_ARGS}' \
		-e 's,(pattern=)%t,\1%h,1' \
		-e 's,-Djruby.home=,-Dpython.cachedir=$${HOME}/.jython-cachedir &,1' \
		${WRKSRC}/bin/${PORTNAME} ${WRKSRC}/conf/logging.properties

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in ${VERTX_DIST}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${DATADIR}/bin/${PORTNAME}
	${LN} -s ${DATADIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	cd ${WRKSRC}/api-docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
