# New ports collection makefile for:	sfdisk
# Date created:				22 April 2006
# Whom:					spam@rm-rf.kiev.ua
#
# $FreeBSD$
#

PORTNAME=	sfdisk
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://src4.narod.ru/

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Standalone sysinstall's fdisk

USE_BZIP2=	yes

PLIST_FILES=	sbin/sfdisk
MAKEFILE=	Makefile.bsd

NOT_FOR_ARCHS=	ia64

.if ${MACHINE} == "pc98"
CFLAGS+=	-DPC98
.endif

.include <bsd.port.mk>
