# $FreeBSD$

CATEGORIES=	print

MAINTAINER=	dinoex@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../cups-base
 
CUPS_CLIENT=	yes

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
