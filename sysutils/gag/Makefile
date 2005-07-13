# New ports collection makefile for:	gag
# Date created:				12 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	gag
PORTVERSION=	4.5d
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Graphical Boot Manager

# security/gag
CONFLICTS=	gag-2*
NO_LATEST_LINK=	yes

USE_ZIP=	yes

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}45

do-install:
# Data
	@${MKDIR} ${DATADIR}
.for f in disk.dsk gag.iso
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

# Documentation (optional)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/install.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
