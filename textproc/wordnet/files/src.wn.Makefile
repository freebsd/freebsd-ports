PROG=		wn
NOMAN=		True	# man pages installed separately

CFLAGS+=	-DUNIX -DDEFAULTPATH="\"${PREFIX}/share/wordnet-1.7\"" \
		-DDEFAULTBIN="\"${PREFIX}/bin\""

CFLAGS+=	-I${.CURDIR}/../../include
LDADD+=		-L../lib -lwn1

BINDIR=		${PREFIX}/bin

.include <bsd.prog.mk>
