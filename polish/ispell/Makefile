# New ports collection makefile for:    pl-ispell
# Date created:                         11 December 2003
# Whom:                                 jmz
#
# $FreeBSD$
#

PORTNAME=	ispell
CATEGORIES=	polish
PKGNAMESUFFIX=	-20021127

MAINTAINER=	wtp@bsdguru.org

ISPELL_PL=	yes
USE_PERL5=	yes

MASTERDIR=	${.CURDIR}/../../textproc/ispell

.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include        "${MASTERDIR}/Makefile"
