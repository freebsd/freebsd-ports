# New ports collection makefile for:	uk-webalizer
# Date created:		22 May 2001
# Whom:			mike@LITech.lviv.ua
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../../www/webalizer
CATEGORIES=	ukrainian

MAINTAINER=	mike@LITech.lviv.ua

LIB_DEPENDS=	gd.4:${PORTSDIR}/ukrainian/gd

WEBALIZER_LANG=	ukrainian
EXTRA_PATCHES+=	${.CURDIR}/files/patch-ba ${.CURDIR}/files/patch-bb

.include "${MASTERDIR}/Makefile"
