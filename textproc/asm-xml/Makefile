# New ports collection makefile for:	asm-xml
# Date created:	   22 February 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	asm-xml
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Very fast XML parser and decoder written in pure assembler

BUILD_DEPENDS=	fasm:${PORTSDIR}/lang/fasm

ONLY_FOR_ARCHS=	i386 amd64
USE_DOS2UNIX=	YES

PLIST_FILES=	include/asm-xml.h lib/libasm-xml.a

post-extract:
	${RM} -rf ${WRKSRC}/obj

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
