# Created by: bf <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libR

COMMENT=	The static libR library from R

DESCR=	${.CURDIR}/pkg-descr
LIBR_SLAVEPORT=	yes
MASTERDIR=	${.CURDIR}/../R
PLIST=	${.CURDIR}/pkg-plist
PLIST_FILES=	lib/R/lib/libR.a
PLIST_DIRSTRY=	lib/R/lib lib/R

.include "${MASTERDIR}/Makefile"
