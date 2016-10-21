# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	asm-xml
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very fast XML parser and decoder written in pure assembler

BUILD_DEPENDS=	fasm:lang/fasm

ONLY_FOR_ARCHS=	i386 amd64
USES=		dos2unix uidfix

PLIST_FILES=	include/asm-xml.h lib/libasm-xml.a

post-extract:
	${RM} -r ${WRKSRC}/obj

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
