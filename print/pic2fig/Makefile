# New ports collection makefile for:    pic2fig
# Date created:         14 Jan 2001
# Whom:                 Patrick Powell <papowell@astart.com>
#
# $FreeBSD$

PORTNAME=	pic2fig
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	utilities
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	papowell@astart.com
COMMENT=	Pic format to fig format converter

WRKSRC=		${WRKDIR}/${PORTNAME}
MAN1=		pic2fig.1
PLIST_FILES=	bin/pic2fig

do-install:
	${INSTALL_PROGRAM} -m 755 ${WRKSRC}/pic2fig ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pic2fig.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
