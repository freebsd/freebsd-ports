PREFIX?=	/usr/local
TCL_DVER?=	8.3
TCL_VER=	${TCL_DVER:S/.//g}
TCL_INCDIR?=	${PREFIX}/include/tcl${TCL_DVER}

CFLAGS+=	-DUNIX -DDEFAULTPATH="\"${PREFIX}/share/wordnet-1.6\"" \
		-DDEFAULTBIN="\"${PREFIX}/bin\""

CFLAGS+=	-I${.CURDIR}/../../include -I$(TCL_INCDIR)

LDADD=		-L../lib -lwn1 -L${PREFIX}/lib -ltcl${TCL_VER} -ltk${TCL_VER}

LIB=		tclwn1
SHLIB_MAJOR=	6
SHLIB_MINOR=	0
SRCS=		stubs.c

INTERNALLIB=	True	# To avoid building the useless static library

all: ${SHLIB_NAME} pkgIndex.tcl

pkgIndex.tcl:
	echo "package ifneeded Wordnet 1.6 [list load \
		[file join ${PREFIX}/lib ${SHLIB_NAME}] Wordnet]" \
			> pkgIndex.tcl

LIBDIR=		${PREFIX}/lib
RESDIR=		${PREFIX}/share/wordnet-1.6/wnres

${LIBDIR} ${RESDIR} ${LIBDIR}/tcl${TCL_DVER}/Wordnet:
	mkdir -p ${.TARGET}

beforeinstall: ${LIBDIR} ${RESDIR} ${LIBDIR}/tcl${TCL_DVER}/Wordnet
	${INSTALL} -C -o ${BINOWN} -g ${BINGRP} -m 444 \
		pkgIndex.tcl ${LIBDIR}/tcl${TCL_DVER}/Wordnet
	${INSTALL} -C -o ${BINOWN} -g ${BINGRP} -m 444 \
		${.CURDIR}/../lib/wnres/*.* ${RESDIR}
	${INSTALL} -C -o ${BINOWN} -g ${BINGRP} -m 755 \
		wnb ${PREFIX}/bin

.include <bsd.lib.mk>
