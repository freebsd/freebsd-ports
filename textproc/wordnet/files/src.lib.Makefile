SRCS=		binsrch.c morph.c search.c setutil.c wnglobal.c \
		wnhelp.c wnrtl.c wnutil.c

CFLAGS+=	-DUNIX -DDEFAULTPATH="\"${PREFIX}/share/wordnet-1.6\"" \
		-DDEFAULTBIN="\"${PREFIX}/bin\"" -Werror

CFLAGS+=	-I${.CURDIR}/../../include

LIB=		wn1
SHLIB_MAJOR=	6
SHLIB_MINOR=	0
NOPROFILE=	True

LIBDIR=		${PREFIX}/lib

.include <bsd.lib.mk>
