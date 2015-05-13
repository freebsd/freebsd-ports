# Created by: ache@FreeBSD.org
# $FreeBSD$

CATEGORIES=

MAINTAINER=	dinoex@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../webalizer

OPTIONS_DEFAULT=GEOIP

WEBALIZER_SUFFIX=	-geoip

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
