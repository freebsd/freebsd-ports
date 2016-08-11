# Created by: Daniel Morante <daniel@morante.net>
# $FreeBSD$

MASTERDIR=	${.CURDIR}/../zetacoin
PKGNAMESUFFIX=	-nox11

OPTIONS_EXCLUDE=	X11 QRCODES

SLAVE_PORT=	yes

BROKEN_armv6=	AtomicPointer not implemented
BROKEN_powerpc64=	Does not build

.include "${MASTERDIR}/Makefile"
