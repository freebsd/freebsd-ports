# New ports collection makefile for:   matrix
# Date created:        27 March 2001
# Whom:                Anton Voronin <anton@urc.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	matrix
PORTVERSION=	1.0
CATEGORIES=	math devel
MASTER_SITES=	http://www.chelcom.ru/~anton/projects/files/
DISTNAME=	matrix-${PORTVERSION}

MAINTAINER=	anton@chelcom.ru
COMMENT=	C++ library to manipulate matrices and vectors

WRKSRC=		${WRKDIR}/matrix

USE_ZIP=	yes
USE_LDCONFIG=	yes
PLIST_SUB=	LIBVERSION=1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		Does not build on amd64 (shared libraries must be compiled with -fPIC)
.endif

.include <bsd.port.post.mk>
