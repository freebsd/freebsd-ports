# $FreeBSD$

CATEGORIES=	news

MAINTAINER=	dinoex@FreeBSD.org

MASTERDIR=	${.CURDIR}/../suck

OPTIONS_DEFAULT=	SSL CNEWS

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
