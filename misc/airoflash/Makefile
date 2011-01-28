# New ports collection makefile for:	airoflash
# Date created:				13 Mar 2002
# Whom:					Doug Ambrisko <ambrisko@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	airoflash
PORTVERSION=	${AF_VERSION}
CATEGORIES=	misc
MASTER_SITES=	"http://airo-linux.cvs.sourceforge.net/viewvc/airo-linux/airo-linux/tools/airoflash.c?revision=${AF_VERSION}"
DISTNAME=	airoflash.c
EXTRACT_SUFX=

MAINTAINER=	ambrisko@FreeBSD.org
COMMENT=	Flash utiltity for Cisco/Aironet 802.11 wireless cards

BROKEN=		fails to fetch

AF_VERSION=	1.7
PLIST_FILES=	bin/airoflash

do-fetch:
		[ -f ${DISTDIR}/${DISTNAME} ] || \
			${FETCH_CMD} -o ${DISTDIR}/${DISTNAME} ${MASTER_SITES}

do-extract:
		${MKDIR} ${WRKSRC}
		${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

.include <bsd.port.mk>
