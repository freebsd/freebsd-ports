# $FreeBSD$

CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../cups-base
 
CUPS_CLIENT=	yes

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
