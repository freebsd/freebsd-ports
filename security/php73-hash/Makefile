# $FreeBSD$

CATEGORIES=	security

MASTERDIR=	${.CURDIR}/../../lang/php73

PKGNAMESUFFIX=	-hash

TEST_TARGET=    test

BROKEN_mips64=		fails to compile: KeccakHash.h: No such file or directory

.include "${MASTERDIR}/Makefile"
