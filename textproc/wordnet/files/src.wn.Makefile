PROG=		wn
NOMAN=		True	# man pages installed separately

CFLAGS+=	-DUNIX -DDEFAULTPATH="\"${PREFIX}/share/WordNet-${VER}\"" \
		-DDEFAULTBIN="\"${PREFIX}/bin\""

CFLAGS+=	-I${.CURDIR}/../../include
LDADD+=		-L../lib -lwn2

BINDIR=		${PREFIX}/bin

.include <bsd.prog.mk>
