# New Ports Collection Makefile For: SimPack
# Date created:        5 June 1997
# Whom:                Ruslan Shevchenko <rssh@cki.ipri.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	simpack
PORTVERSION=	3.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.cis.ufl.edu/pub/simdigest/tools/
DISTFILES=	SimPack3.tar.Z

MAINTAINER=	rssh@cki.ipri.kiev.ua

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4

USE_XLIB=	yes
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/simpack

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
VERSION=	1
.else
VERSION=	1.0
.endif

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/func/queuing/queuing.c \
		${WRKSRC}/func/queuing/queuing.h

post-build: create-libs create-scripts

do-install: do-install-bin do-install-include do-install-lib do-install-doc

post-install:
	@${SH} ${PKGREQ} ${PKGNAME} INSTALL

do-install-bin:
	@for i in `${CAT} ${FILESDIR}/FILES-BIN` ; do \
	  ${INSTALL_PROGRAM} ${WRKSRC}/$$i ${PREFIX}/bin; \
	done
	@${INSTALL_SCRIPT} ${WRKDIR}/temp/sdsmt.alias ${PREFIX}/bin/sdsmt
	@${INSTALL_SCRIPT} ${WRKDIR}/temp/deq.alias ${PREFIX}/bin/deq

do-install-include:
	@${MKDIR} ${PREFIX}/include/Sim++
	@for i in `${CAT} ${FILESDIR}/FILES-INCLUDE-SIMPP` ; do      \
	  ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/include/Sim++ ; \
	done
	@${MKDIR} ${PREFIX}/include/queuing
	@for i in `${CAT} ${FILESDIR}/FILES-INCLUDE-QUEUING` ; do       \
	  ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/include/queuing/ ; \
	done

do-install-lib:
	@${MKDIR} ${PREFIX}/lib/Sim++/olb
	@for i in `${CAT} ${FILESDIR}/FILES-OLB` ; do                 \
	  ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/lib/Sim++/olb/ ; \
	done
	@for i in `${CAT} ${FILESDIR}/DIRS-LIB` ; do \
	  ${MKDIR} ${PREFIX}/lib/SimPack/$$i ;    \
	done
	@for i in `${CAT} ${FILESDIR}/FILES-LIB` ; do                  \
	  ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/lib/SimPack/$$i ; \
	done
	@${INSTALL_DATA} ${WRKDIR}/temp/libsim++.a ${PREFIX}/lib/libsim++.a
	@${INSTALL_DATA} ${WRKDIR}/temp/libsim++.so.${VERSION} ${PREFIX}/lib
	@${LN} -sf libsim++.so.${VERSION} ${PREFIX}/lib/libsim++.so
	@${INSTALL_DATA} ${WRKDIR}/temp/libqueuing.a ${PREFIX}/lib/libqueuing.a;
	@${INSTALL_DATA} ${WRKDIR}/temp/libqueuing.so.${VERSION} ${PREFIX}/lib
	@${LN} -sf libqueuing.so.${VERSION} ${PREFIX}/lib/libqueuing.so

do-install-doc:
	@for i in `${CAT} ${FILESDIR}/DIRS-SHARE` ; do \
	  ${MKDIR} ${PREFIX}/share/SimPack/$$i; \
	done
	@for i in `${CAT} ${FILESDIR}/FILES-SHARE` ; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/SimPack/$$i ; \
	done

create-libs: create-lib-sim++ create-lib-queuing

create-lib-sim++:
	@${ECHO} libsim++.a
	@${MKDIR} ${WRKDIR}/temp
	@(cd ${WRKDIR}/temp;                            \
	for i in `${CAT} ${FILESDIR}/FILES-SRC-SIMPP` ; do \
	  gcc -I${WRKSRC}/func/event/include -c -O      \
		${WRKSRC}/func/event/src/$$i ;          \
	done;                                           \
	${AR} cq libsim++.a `lorder *.o | tsort -q `;   \
	${RM} *.o )
	@${ECHO} libsim++.so.${VERSION}
	@(cd ${WRKDIR}/temp;                                   \
	for i in `${CAT} ${FILESDIR}/FILES-SRC-SIMPP` ; do        \
	  gcc -fpic -DPIC -I${WRKSRC}/func/event/include -c -O \
		-o `${BASENAME} $$i cpp`.so                      \
		${WRKSRC}/func/event/src/$$i ;                \
	done;                                   \
	if [ "${PORTOBJFORMAT}" = "elf" ]; then \
		${LD} -shared -x -soname libsim++.so.${VERSION} -o \
		  libsim++.so.${VERSION} `lorder *.so | tsort -q ` ; \
	else \
		${LD} -Bshareable -x -o libsim++.so.${VERSION} \
		  `lorder *.so | tsort -q ` ;           \
	fi; \
	${RM} *.so )

create-lib-queuing:
	@${ECHO} libqueuing.a
	@(cd ${WRKDIR}/temp;                            \
	gcc -I${WRKSRC}/func/queuing -c -O              \
	      ${WRKSRC}/func/queuing/queuing.c;         \
	${AR} cq libqueuing.a `lorder *.o | tsort -q `; \
	${RM} *.o )
	@${ECHO} libqueuing.so.${VERSION}
	@(cd ${WRKDIR}/temp;                           \
	gcc -fpic -DPIC -I${WRKSRC}/func/queuing -c -O \
		 -o queuing.so                         \
		${WRKSRC}/func/queuing/queuing.c ;    \
	if [ "${PORTOBJFORMAT}" = "elf" ]; then \
		${LD} -shared -x -soname libqueuing.so.${VERSION} -o \
		  libqueuing.so.${VERSION} `lorder *.so | tsort -q ` ; \
	else \
		${LD} -Bshareable -x -o libqueuing.so.${VERSION} \
		  `lorder *.so | tsort -q ` ;           \
	fi; \
	${RM} *.so )

create-scripts: create-sdsmt-alias create-deq-alias

create-sdsmt-alias:
	@${ECHO_CMD} SDSMTLIB=${PREFIX}/lib/SimPack/func/slice/sdsmt \
				>  ${WRKDIR}/temp/sdsmt.alias
	@${ECHO_CMD} export SDSMTLIB >> ${WRKDIR}/temp/sdsmt.alias
	@${ECHO_CMD} wish4.1 ${PREFIX}/lib/SimPack/func/slice/sdsmt/sdsmt \
				>> ${WRKDIR}/temp/sdsmt.alias

create-deq-alias:
	@${ECHO_CMD} PATCH=${PREFIX}/lib/SimPack/constraint/differential:$$PATCH \
				>  ${WRKDIR}/temp/deq.alias
	@${ECHO_CMD} export PATCH >> ${WRKDIR}/temp/deq.alias
	@${ECHO_CMD} ${PREFIX}/lib/SimPack/constraint/differential/deq $$*       \
				>> ${WRKDIR}/temp/deq.alias

.include <bsd.port.post.mk>
