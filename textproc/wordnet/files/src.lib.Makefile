SRCS=		binsrch.c morph.c search.c setutil.c wnglobal.c \
		wnhelp.c wnrtl.c wnutil.c

CFLAGS+=	-DUNIX -DDEFAULTPATH="\"${PREFIX}/share/WordNet-${VER}\"" \
		-DDEFAULTBIN="\"${PREFIX}/bin\""

CFLAGS+=	-I${.CURDIR}/../../include

LIB=		wn2
SHLIB_MAJOR=	0
NOPROFILE=	True

LIBDIR=		${PREFIX}/lib

.include <bsd.lib.mk>
