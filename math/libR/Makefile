# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libR

COMMENT=	The static libR library from R

DESCR=	${.CURDIR}/pkg-descr
LIBR_SLAVEPORT=	yes
MASTERDIR=	${.CURDIR}/../R
PLIST=	${.CURDIR}/pkg-plist
PLIST_FILES=	lib/R/lib/libR.a

BROKEN_powerpc64=	Does not build

.include "${MASTERDIR}/Makefile"
