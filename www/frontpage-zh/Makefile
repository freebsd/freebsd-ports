# New ports collection makefile for:	FrontPage Chinese Web Administration
# Date created:		Sat Oct 25 16:30:00 CDT 2001
# Whom:			hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	frontpage
CATEGORIES=	www chinese
PKGNAMEPREFIX=	zh-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Microsoft Frontpage Chinese Web Administration

MD5_FILE=	${.CURDIR}/distinfo
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

FP_LANG=	chp chs cht
FP_LANGUAGE=	Chinese
FP_LCID=	1028 2052 3076
NO_FP_LCID_SUB=	yes

MASTERDIR=	${.CURDIR}/../frontpage-ar

.include "${MASTERDIR}/Makefile"
