# $FreeBSD$

CATEGORIES=	portuguese
PKGNAMEPREFIX?=	pt_BR-

MAINTAINER=	ports@FreeBSD.org

MASTERDIR?=	${.CURDIR}/../../www/webalizer
WEBALIZER_LANG=	portuguese_brazil

NO_STAGE=	yes
.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${MASTERDIR}/Makefile"
