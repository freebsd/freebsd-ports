# $FreeBSD$

CATEGORIES=	security

MASTERDIR=	${.CURDIR}/../../lang/php72

PKGNAMESUFFIX=	-hash

BROKEN_mips64=		fails to compile: KeccakHash.h: No such file or directory
BROKEN_powerpc64=	fails to compile: KeccakHash.h: No such file or directory

TEST_TARGET=    test

.include "${MASTERDIR}/Makefile"
