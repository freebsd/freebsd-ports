# New ports collection makefile for:	nfsshell
# Date created:				5 February 2005
# Whom:					johans@stack.nl
#
# $FreeBSD$
#

PORTNAME=	nfsshell
PORTVERSION=	19980519
CATEGORIES=	net
MASTER_SITES=	http://www.cs.vu.nl/pub/leendert/
DISTNAME=	${PORTNAME}

MAINTAINER=	johans@stack.nl
COMMENT=	Userland NFS command tool

WRKSRC=		${WRKDIR}/nfs
ALL_TARGET=	nfs
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -DREADLINE" LIBS="-lreadline"

PLIST_FILES=	bin/nfsshell

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nfs ${PREFIX}/bin/nfsshell

.include <bsd.port.mk>
