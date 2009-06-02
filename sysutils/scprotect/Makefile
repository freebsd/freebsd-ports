# New ports collection Makefile for:	scprotect
# Date created:		5 Feb 2009
# Whom:			Denis Barov  <dindin@dindin.ru>
#
# $FreeBSD$
#

PORTNAME=	scprotect
PORTVERSION=	20090209
PORTREVISION=	1
CATEGORIES=	sysutils kld
MASTER_SITES=	http://dindin.ru/download/

MAINTAINER=	dindin@dindin.ru
COMMENT=	Protect process from killing when the swap space is exhausted

NO_PACKAGE=	Needs to be compiled for specific kernel

KMODDIR?=	/boot/modules
SRC_BASE?=	/usr/src

PLIST_SUB=	KMODDIR=${KMODDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV+=	KMODDIR=${KMODDIR}

MAN8=		scprotect.8
MANCOMPRESSED=	maybe

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel sources
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
