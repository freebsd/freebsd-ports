# $FreeBSD$

CATEGORIES=	print

MAINTAINER=	c.petrik.sosa@gmail.com

MASTERDIR?=	${.CURDIR}/../cups-base
 
CUPS_CLIENT=	yes

.if exists(${.CURDIR}/Makefile.local)
NO_STAGE=	yes
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
