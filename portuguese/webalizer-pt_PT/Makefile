# $FreeBSD$

CATEGORIES=	portuguese
PKGNAMEPREFIX?=	pt_PT-

MAINTAINER=	ports@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../../www/webalizer
WEBALIZER_LANG=	portuguese

NO_STAGE=	yes
.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
