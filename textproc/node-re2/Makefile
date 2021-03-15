# $FreeBSD$

PORTNAME=	re2
DISTVERSION=	1.15.9
CATEGORIES=	textproc
PKGNAMEPREFIX=	node-

MAINTAINER=	otis@FreeBSD.org
COMMENT=	Node.js bindings for devel/re2

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/bin/node-gyp:devel/node-gyp \
		${LOCALBASE}/bin/npm:www/npm \
		${LOCALBASE}/lib/node_modules/nan:devel/node-nan
LIB_DEPENDS=	libre2.so:devel/re2 \
		libuv.so:devel/libuv
RUN_DEPENDS=	${LOCALBASE}/bin/npm:www/npm

USES=		gmake python

USE_GITHUB=	yes
GH_ACCOUNT=	uhop
GH_PROJECT=	node-re2

.include <bsd.port.pre.mk>

_NODECMD=	${LOCALBASE}/bin/node --version
_NPMCMD=	${LOCALBASE}/bin/npm
_RE2DIR=	${STAGEDIR}${PREFIX}/lib/node_modules/re2
_DEVDIR:=	${WRKDIR}/.devdir

pre-configure:
	${RM} ${WRKSRC}/package-lock.json
	(_NPMGROOT=$$(${_NPMCMD} root -g) && \
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" \
	-e "s|%%NODEPATH%%|$${_NPMGROOT}|g" ${WRKSRC}/binding.gyp)
# Determine node's version. Particular node version is
# pulled in via www/npm dependency
	(_NODEVER=$$(${_NODECMD} | ${SED} -n 's|^v\(.*\)|\1|p') && \
	${MKDIR} ${_DEVDIR}/$${_NODEVER}/include && \
	${RLN} ${LOCALBASE}/include/node ${_DEVDIR}/$${_NODEVER}/include/node && \
	${ECHO} "9" > ${_DEVDIR}/$${_NODEVER}/installVersion \
	)

do-configure:
	(cd ${WRKSRC} && \
		${SETENV} HOME=${WRKDIR} NODE_PATH=${LOCALBASE}/lib/node_modules/npm/node_modules \
		${LOCALBASE}/bin/node-gyp configure --python=${PYTHON_CMD} \
		--devdir=${_DEVDIR})

do-build:
	(cd ${WRKSRC} && \
		${SETENV} HOME=${WRKDIR} NODE_PATH=${LOCALBASE}/lib/node_modules/npm/node_modules \
		${LOCALBASE}/bin/node-gyp build \
		--devdir=${_DEVDIR})

do-install:
	${MKDIR} ${_RE2DIR}
	${RM} -r ${WRKSRC}/build/Release/obj.target
	${STRIP_CMD} ${WRKSRC}/build/Release/re2.node
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${_RE2DIR} \
		"! ( -name \.* -or -name binding\.gyp\.* \
		-or -path */\.* -or -name vendor )"

.include <bsd.port.post.mk>
