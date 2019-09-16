# $FreeBSD$

PORTNAME=	go-appengine-sdk
DISTVERSION=	1.9.70
CATEGORIES=	www devel
MASTER_SITES=	https://storage.googleapis.com/appengine-sdks/featured/
DISTNAME=	${PORTNAME:S,-,_,g}_linux_amd64-${PORTVERSION}

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	App Engine SDK for Go

# The actual license for this port is "APACHE20 and BSD3CLAUSE and MIT and PSFL and (GPLv2+ or LGPL21+ or MPL11)".
LICENSE=	APACHE20 BSD3CLAUSE GPLv2+ LGPL21+ MIT MPL11 PSFL
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_MIT=		${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=${PYTHON_VER}:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6:security/py-pycrypto@${PY_FLAVOR}

USES=		gettext go python:2.7 shebangfix zip

SHEBANG_GLOB=	*.py *.bash *.sh *.pl *.cgi goapp
WRKSRC=		${WRKDIR}/go_appengine

GAEDATADIRS=	google lib tools
GAEGOROOTS=	goroot-1.9
GAESCRIPTS=	appcfg.py backends_conversion.py \
		bulkload_client.py bulkloader.py dev_appserver.py \
		download_appstats.py endpointscfg.py run_tests.py \
		wrapper_util.py
GOARCH=		${ARCH:S,i386,386,}

PLIST_FILES=	${GAESCRIPTS:C,(.+)\.py,bin/\1-go,} \
		bin/goapp
PLIST_DIRS=	${GAEGOROOTS:C,(.+),${DATADIR}/\1/pkg/obj/${OPSYS:tl}_${GOARCH},}

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFINE_i386=	SSE2
OPTIONS_DEFAULT_i386=	SSE2
SSE2_DESC=		Generate code with SSE2 (check off for old x86 CPUs)

SSE2_VARS_OFF=		GO386=387

PORTDATA=	*
PORTEXAMPLES=	*

do-build:
	@for R in ${GAEGOROOTS}; do \
		(cd ${WRKSRC}/$${R}/src && \
			${SETENV} ${MAKE_ENV} \
			GOROOT_BOOTSTRAP=${LOCALBASE}/go \
			GOOS=${OPSYS:tl} GOARCH=${GOARCH} \
			GO386=${GO386} \
			${SH} make.bash); \
		(cd ${WRKSRC}/$${R}/bin && \
			${RM} godoc cover && ${MV} go goapp); \
		(cd ${WRKSRC}/$${R} && \
			${RM} -rf ./pkg/linux_amd64_appengine ./pkg/tool/linux_amd64); \
	done
	# Create wrapper scripts to avoid conflicts with other AppEngine SDK(s)
	@cd ${WRKSRC} && \
		for S in ${GAESCRIPTS} goapp; do \
			${ECHO} "#!/bin/sh" >> $${S%.py}-go; \
			${ECHO} "${PYTHON_CMD} ${DATADIR}/$${S} \$$*" >> $${S%.py}-go; \
		done

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	for S in ${GAESCRIPTS} _python_runtime.py goapp; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$${S} ${STAGEDIR}${DATADIR}; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/*-go ${STAGEDIR}${PREFIX}/bin
	${MV} ${STAGEDIR}${PREFIX}/bin/goapp-go ${STAGEDIR}${PREFIX}/bin/goapp
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} "${GAEDATADIRS}" ${STAGEDIR}${DATADIR} && \
		${CP} -a ${GAEGOROOTS} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${STAGEDIR}${DATADIR}
	cd ${STAGEDIR}${DATADIR} && \
		${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${DATADIR} -f ${GAEDATADIRS} -q

do-install-EXAMPLES-on:
	cd ${WRKSRC}/demos && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
