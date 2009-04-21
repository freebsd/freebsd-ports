# New ports collection makefile for:	poster
# Date created:		7 March 2008
# Whom:			Bruce M. Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde_poster
PORTVERSION=	1.0
CATEGORIES=	print kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	printing
PKGNAMESUFFIX?=	# empty
DISTNAME=	poster

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE version of the poster utility

USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	poster
WRKSRC=		${WRKDIR}/${DISTNAME}-20060221

CONFLICTS?=	poster-[0-9]*

MAN1=		poster.1
PLIST_FILES=	bin/poster

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
