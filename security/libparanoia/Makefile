# New ports collection makefile for:	libparanoia
# Version required:			1.3
# Date created:				1 Jan 1999
# Whom:					Alexandre Snarskii <snar@paranoia.ru>
#
# $Id: Makefile,v 1.1.1.1 1999/04/10 13:12:12 jseger Exp $

DISTNAME=	libparanoia-1.3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	snar@paranoia.ru

ONLY_FOR_ARCHS=	i386

# this library depends on system-defined headers "SYS.h" and "DEFS.h"
# which may differ from release to release.

.if !exists(/usr/src/lib/libc)
BROKEN=		You need to have libc sources installed in /usr/src/lib/libc \
		before compiling.
.endif

.include <bsd.port.mk>
