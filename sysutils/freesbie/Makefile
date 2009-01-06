# New ports collection makefile for:	FreeSBIE
# Date created:		27 March 2003
# Whom:			Thomas E. Zander <riggs@rrr.de>
#
# $FreeBSD$
#

PORTNAME=	freesbie
PORTVERSION=	2.0.20070710
CATEGORIES=	sysutils
MASTER_SITES=	http://www.rrr.de/~riggs/freesbie/
MASTER_SITES+=	${MASTER_SITE_LOCAL:S/%SUBDIR%/delphij/}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/2.0.//}

MAINTAINER=	riggs@rrr.de
COMMENT=	Yet another cool answer to the system-on-cd question

USE_BZIP2=	yes
USE_CDRTOOLS=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}2

do-install:
	@ ${MKDIR} ${DATADIR}
	@ cd ${WRKSRC} && ${FIND} . -type f -print | tar -cf - -T - | \
	tar -xf - -C ${DATADIR}

.include <bsd.port.mk>
