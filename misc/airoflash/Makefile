# New ports collection makefile for:	airoflash
# Date created:				13 Mar 2002
# Whom:					Doug Ambrisko <ambrisko@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	airoflash
PORTVERSION=	${AF_VERSION}
CATEGORIES=	misc
MASTER_SITES=	"http://cvs.sourceforge.net/cgi-bin/viewcvs.cgi/~checkout~/airo-linux/airo-linux/tools/airoflash.c?rev=${AF_VERSION}"
DISTNAME=	airoflash.c
EXTRACT_SUFX=

MAINTAINER=	ambrisko@freebsd.org

AF_VERSION=	1.3

do-fetch:
		${FETCH_CMD} -o ${DISTDIR}/${DISTNAME} ${MASTER_SITES}

do-extract:
		${MKDIR} ${WRKSRC}
		${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

.include <bsd.port.mk>
