# Created by: jmz
# $FreeBSD$

PORTNAME=	ispell
CATEGORIES=	polish
PKGNAMESUFFIX=	-20021127

MAINTAINER=	wtp@bsdguru.org

ISPELL_PL=	yes
USES=		perl5

MASTERDIR=	${.CURDIR}/../../textproc/ispell

.if exists(${.CURDIR}/Makefile.local)
NO_STAGE=	yes
.include "${.CURDIR}/Makefile.local"
.endif

.include        "${MASTERDIR}/Makefile"
