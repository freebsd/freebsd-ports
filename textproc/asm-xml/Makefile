# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	asm-xml
PORTVERSION=	1.1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very fast XML parser and decoder written in pure assembler

BUILD_DEPENDS=	fasm:${PORTSDIR}/lang/fasm

ONLY_FOR_ARCHS=	i386 amd64
USE_DOS2UNIX=	YES

PLIST_FILES=	include/asm-xml.h lib/libasm-xml.a

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build on 6.X
.endif

post-extract:
	${RM} -rf ${WRKSRC}/obj

post-patch:
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.post.mk>
