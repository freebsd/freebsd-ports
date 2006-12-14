# New ports collection makefile for:	libparanoia
# Date created:				1 Jan 1999
# Whom:					Alexandre Snarskii <snar@paranoia.ru>
#
# $FreeBSD$

PORTNAME=	libparanoia
PORTVERSION=	1.4.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Safe (in the mean of stack smashing) reincarnation of strcpy et al

ONLY_FOR_ARCHS=	i386

USE_LDCONFIG=	yes

# this library depends on system-defined headers "SYS.h" and "DEFS.h"
# which may differ from release to release.

.if !exists(/usr/src/lib/libc)
IGNORE=		you need to have libc sources installed in /usr/src/lib/libc \
		before compiling
.endif

.include <bsd.port.pre.mk>

do-patch:
	@${REINPLACE_CMD} -e 's|#include <varargs.h>||' \
		${WRKSRC}/stentry.c

.include <bsd.port.post.mk>
