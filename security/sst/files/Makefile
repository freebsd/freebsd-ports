PROG=sst

BINDIR=${PREFIX}/sbin
MANDIR=${PREFIX}/man/man

CFLAGS+=	-DCONFDIR='"${OPENSSLDIR}"' -DCERTF='"certs/sst.pem"' \
		-I${OPENSSLINC} -Wno-comment
CFLAGS+=	-Wno-deprecated
CFLAGS+=	-Wno-dangling-else
.if exists(/usr/bin/nc)
CFLAGS+=	-DNETCAT='"/usr/bin/nc"'
.else
CFLAGS+=	-DNETCAT='"${LOCALBASE}/bin/netcat"'
.endif
LDADD+=	-L${OPENSSLLIB} -lssl -lcrypto

.include <bsd.prog.mk>
