# Created by: ache@FreeBSD.org
# $FreeBSD$

CATEGORIES=

MAINTAINER=	dinoex@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../webalizer
WITH_GEOIP=	yes

.if exists(${.CURDIR}/Makefile.local)
NO_STAGE=	yes
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
