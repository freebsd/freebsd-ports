# New ports collection makefile for:	hilite
# Date created:				21 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	hilite
PORTVERSION=	1.5
CATEGORIES=	sysutils
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.c

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A command-line utility to highlight anything printed to stderr

MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/hilite

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
