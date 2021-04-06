PROG=	ipv6mon
LDADD=	-lpcap

PREFIX?=	/usr/local

FILES=		ipv6mon.conf
FILESNAME=	ipv6mon.conf.sample
FILESDIR=	${PREFIX}/etc

BINDIR=		${PREFIX}/sbin
MANDIR=		${PREFIX}/man/man

MAN=	ipv6mon.8 ipv6mon.conf.5
NO_MANCOMPRESS=

.include <bsd.prog.mk>
