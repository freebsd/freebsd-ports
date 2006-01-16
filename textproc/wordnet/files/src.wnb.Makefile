PREFIX?=	/usr/local
TCL_DVER?=	8.4
TCL_VER=	${TCL_DVER:S/.//g}
TCL_INCDIR?=	${PREFIX}/include/tcl${TCL_DVER}

CFLAGS+=	-DUNIX -DDEFAULTPATH="\"${PREFIX}/share/WordNet\"" \
		-DDEFAULTBIN="\"${PREFIX}/bin\"" -DHAVE_LANGINFO_CODESET

CFLAGS+=	-I${.CURDIR}/../../include -I$(TCL_INCDIR)

LDADD=		-L.. -lWN -L${PREFIX}/lib -ltcl${TCL_VER} # -ltk${TCL_VER}

SHLIB_NAME=	libtclwn2.so.0
SRCS=		stubs.c

.PATH:	${.CURDIR:H:H}/src

all: pkgIndex.tcl

pkgIndex.tcl:
	echo "package ifneeded Wordnet ${VER} [list load \
		[file join ${PREFIX}/lib ${SHLIB_NAME}] Wordnet]" \
			> pkgIndex.tcl

LIBDIR=		${PREFIX}/lib
RESDIR=		${PREFIX}/share/WordNet/

${LIBDIR} ${RESDIR} ${LIBDIR}/tcl${TCL_DVER}/Wordnet:
	mkdir -p ${.TARGET}

beforeinstall: ${LIBDIR} ${RESDIR} ${LIBDIR}/tcl${TCL_DVER}/Wordnet
	${BSD_INSTALL_DATA} pkgIndex.tcl ${LIBDIR}/tcl${TCL_DVER}/Wordnet
	${BSD_INSTALL_DATA} ${.CURDIR}/*.xbm ${RESDIR}
	${BSD_INSTALL_SCRIPT} ${.CURDIR:H:H}/src/wnb ${PREFIX}/bin

.include <bsd.lib.mk>
