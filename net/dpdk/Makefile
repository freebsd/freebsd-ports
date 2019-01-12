# $FreeBSD$

PORTNAME=	dpdk
PORTVERSION=	18.05.1
CATEGORIES=	net
MASTER_SITES=	http://fast.dpdk.org/rel/

MAINTAINER=	bruce.richardson@intel.com
COMMENT=	DPDK: Software libraries for packet processing

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Only works on 64-bit x86 hardware

USES=		gmake kmod shebangfix
SHEBANG_FILES=	usertools/dpdk-pmdinfo.py
MAKEFILE=	GNUmakefile
NO_PACKAGE=	ignores cflags
WRKSRC=		${WRKDIR}/${PORTNAME}-stable-${PORTVERSION}
RTE_TARGET=	x86_64-native-bsdapp-clang
WRKBUILD=	${WRKSRC}/${RTE_TARGET}
MAKE_ENV=	V=1

ALL_TARGET=	install T=${RTE_TARGET}

OPTIONS_DEFINE=	EXAMPLES DEBUG TOOLS
OPTIONS_DEFAULT=TOOLS
OPTIONS_SUB=	yes
DEBUG_DESC=	Debugging support (unoptimized build, impacts performance)
TOOLS_DESC=	Install tool scripts

DEBUG_MAKE_ENV=	EXTRA_CFLAGS='-O0 -g'
TOOLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>=0:devel/py-pyelftools@${PY_FLAVOR}
TOOLS_USES=	python:2.7

# build up the list of files in the compiled directory that should be executable
EXEC_FILES=	app/testpmd

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${RTE_TARGET}/app \
	  ${STAGEDIR}${DATADIR}/${RTE_TARGET}/lib \
	  ${STAGEDIR}${DATADIR}/${RTE_TARGET}/include/generic
	cd ${WRKSRC} && ${COPYTREE_SHARE} mk ${STAGEDIR}${DATADIR} \
	   && ${COPYTREE_SHARE} examples ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKBUILD}/.config ${STAGEDIR}${DATADIR}/${RTE_TARGET}
	for f in ${EXEC_FILES} ; do \
		${INSTALL_PROGRAM} ${WRKBUILD}/$$f ${STAGEDIR}${DATADIR}/${RTE_TARGET}/app; \
	done
	for f in ${WRKBUILD}/lib/* ; do \
		${INSTALL_DATA} $$f ${STAGEDIR}${DATADIR}/${RTE_TARGET}/lib ; \
	done
	for f in ${WRKBUILD}/include/*.h ; do \
		${INSTALL_DATA} $$f ${STAGEDIR}${DATADIR}/${RTE_TARGET}/include ; \
	done
	for f in ${WRKBUILD}/include/generic/*.h ; do \
		${INSTALL_DATA} $$f ${STAGEDIR}${DATADIR}/${RTE_TARGET}/include/generic ; \
	done
	${LN} -sf ${DATADIR}/${RTE_TARGET}/lib ${STAGEDIR}${PREFIX}/lib/dpdk
	${LN} -sf ${DATADIR}/${RTE_TARGET}/include ${STAGEDIR}${PREFIX}/include/dpdk
	${INSTALL_KLD} ${WRKBUILD}/kmod/* ${STAGEDIR}${KMODDIR}

do-install-EXAMPLES-on:
	${LN} -sf ${DATADIR}/examples ${STAGEDIR}${EXAMPLESDIR}

do-install-TOOLS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/usertools/dpdk-pmdinfo.py ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
