# $FreeBSD$

PORTNAME=	dpdk
PORTVERSION=	16.07
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.dpdk.org/browse/dpdk/snapshot/

MAINTAINER=	bruce.richardson@intel.com
COMMENT=	DPDK: Software libraries for packet processing

LICENSE=	BSD3CLAUSE

USES=		execinfo gmake kmod
MAKEFILE=	GNUmakefile
ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Only works on 64-bit x86 hardware
NO_PACKAGE=	ignores cflags
RTE_TARGET=	x86_64-native-bsdapp-clang
WRKBUILD=	${WRKSRC}/${RTE_TARGET}
MAKE_ENV=	V=1

ALL_TARGET=	install T=${RTE_TARGET}

OPTIONS_DEFINE=	DEBUG TOOLS
OPTIONS_SUB=	yes
DEBUG_DESC=	Debugging support (unoptimized build, impacts performance)
TOOLS_DESC=	Install tool scripts

DEBUG_MAKE_ENV=	EXTRA_CFLAGS='-O0 -g'
TOOLS_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyelftools>=0:devel/py-pyelftools
TOOLS_USES=	python

# build up the list of files in the compiled directory that should be executable
EXEC_FILES=	app/cmdline_test \
		app/testpipeline \
		app/testpmd \
		app/testacl \
		app/test

post-patch:
	@${REINPLACE_CMD} -e 's|%%EXECINFO_CPPFLAGS%%|${EXECINFO_CPPFLAGS}|g' \
		-e 's|%%EXECINFO_LDFLAGS%%|${EXECINFO_LDFLAGS}|g' \
		${WRKSRC}/mk/exec-env/bsdapp/rte.vars.mk

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${RTE_TARGET}/app \
	  ${STAGEDIR}${DATADIR}/${RTE_TARGET}/lib \
	  ${STAGEDIR}${DATADIR}/${RTE_TARGET}/include/generic \
	  ${STAGEDIR}${DATADIR}/${RTE_TARGET}/include/exec-env
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
	for f in ${WRKBUILD}/include/exec-env/*.h ; do \
		${INSTALL_DATA} $$f ${STAGEDIR}${DATADIR}/${RTE_TARGET}/include/exec-env ; \
	done
	${LN} -sf ${DATADIR}/${RTE_TARGET}/lib ${STAGEDIR}${PREFIX}/lib/dpdk
	${LN} -sf ${DATADIR}/${RTE_TARGET}/include ${STAGEDIR}${PREFIX}/include/dpdk
	${LN} -sf ${DATADIR}/examples ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_KLD} ${WRKBUILD}/kmod/* ${STAGEDIR}${KMODDIR}

do-install-TOOLS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/dpdk-pmdinfo.py ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
