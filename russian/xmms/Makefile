# New ports collection makefile for:	xmms
# Date created:				9 November 2003
# Whom:					oleg dashevskii <be9-ml@be9.ru>
#
# $FreeBSD$
#

PORTNAME=	xmms
CATEGORIES=	russian

MAINTAINER=	be9-ml@be9.ru
COMMENT=	RusXMMS - X Multimedia System with Russian encoding patch

BROKEN=		"Doesn't build with multimedia/xmms version 1.2.10"

MASTERDIR=	${.CURDIR}/../../multimedia/xmms

CONFLICTS=	xmms-[0-9]*

WITH_ENCODING_PATCH=	yes
MD5_FILE=	${.CURDIR}/distinfo

.include "${MASTERDIR}/Makefile"
