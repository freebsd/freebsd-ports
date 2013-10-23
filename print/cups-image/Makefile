# $FreeBSD$

CATEGORIES=	print

MAINTAINER=	ports@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../cups-base
 
CUPS_IMAGE=	yes

NO_STAGE=	yes

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
