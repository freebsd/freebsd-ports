# New ports collection makefile for:	libparanoia
# Date created:				1 Jan 1999
# Whom:					Alexandre Snarskii <snar@paranoia.ru>
#
# $FreeBSD$

PORTNAME=	libparanoia
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.lexa.ru/pub/domestic/snar/

MAINTAINER=	snar@paranoia.ru

ONLY_FOR_ARCHS=	i386

INSTALLS_SHLIB=	yes

# this library depends on system-defined headers "SYS.h" and "DEFS.h"
# which may differ from release to release.

.if !exists(/usr/src/lib/libc)
BROKEN=		You need to have libc sources installed in /usr/src/lib/libc \
		before compiling.
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500039
post-patch:
	@(cd ${_DISTDIR};${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/vsnprintf-current.patch)
.endif

.include <bsd.port.post.mk>
