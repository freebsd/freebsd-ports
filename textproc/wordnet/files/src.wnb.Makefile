PREFIX?=	/usr/local
TCL_DVER?=	8.4
TCL_VER=	${TCL_DVER:S/.//g}
TCL_INCDIR?=	${PREFIX}/include/tcl${TCL_DVER}

CFLAGS+=	-DUNIX -DDEFAULTPATH="\"${PREFIX}/share/WordNet-${VER}\"" \
		-DDEFAULTBIN="\"${PREFIX}/bin\""

CFLAGS+=	-I${.CURDIR}/../../include -I$(TCL_INCDIR)

LDADD=		-L../lib -lwn2 -L${PREFIX}/lib -ltcl${TCL_VER} -ltk${TCL_VER}

SHLIB_NAME=	libtclwn2.so.0
SRCS=		stubs.c

all: pkgIndex.tcl

pkgIndex.tcl:
	echo "package ifneeded Wordnet ${VER} [list load \
		[file join ${PREFIX}/lib ${SHLIB_NAME}] Wordnet]" \
			> pkgIndex.tcl

LIBDIR=		${PREFIX}/lib
RESDIR=		${PREFIX}/share/WordNet-${VER}/wnres

${LIBDIR} ${RESDIR} ${LIBDIR}/tcl${TCL_DVER}/Wordnet:
	mkdir -p ${.TARGET}

beforeinstall: ${LIBDIR} ${RESDIR} ${LIBDIR}/tcl${TCL_DVER}/Wordnet
	${INSTALL} -C -o ${BINOWN} -g ${BINGRP} -m 444 \
		pkgIndex.tcl ${LIBDIR}/tcl${TCL_DVER}/Wordnet
	${INSTALL} -C -o ${BINOWN} -g ${BINGRP} -m 444 \
		${.CURDIR}/../lib/wnres/license.txt \
		${.CURDIR}/../lib/wnres/*.xbm ${RESDIR}
	${INSTALL} -C -o ${BINOWN} -g ${BINGRP} -m 755 \
		wnb ${PREFIX}/bin

.include <bsd.lib.mk>
