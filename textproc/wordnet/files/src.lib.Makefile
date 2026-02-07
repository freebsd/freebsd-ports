SRCS=		binsrch.c morph.c search.c wnglobal.c \
		wnhelp.c wnrtl.c wnutil.c

CFLAGS+=	-DUNIX -DDEFAULTPATH="\"${PREFIX}/share/WordNet\""\
		-DDEFAULTBIN="\"${PREFIX}/bin\""

CFLAGS+=	-I${.CURDIR:H}/include

LIB=		WN
WARNS=		5
SHLIB_MAJOR=	2
WITHOUT_PROFILE=	True

LIBDIR=		${PREFIX}/lib

.include <bsd.lib.mk>
