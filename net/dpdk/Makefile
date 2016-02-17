# $FreeBSD$

PORTNAME=	dpdk
PORTVERSION=	2.2.0
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

ALL_TARGET=	install T=${RTE_TARGET}

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
	${MKDIR} ${STAGEDIR}${DATADIR}/${RTE_TARGET}/app \
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

.include <bsd.port.mk>
