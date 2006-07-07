# New ports collection makefile for:	gag
# Date created:				12 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	gag
PORTVERSION=	4.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Graphical Boot Manager

ONLY_FOR_ARCHS=	i386
USE_ZIP=	yes
NO_BUILD=	yes

# security/gag
CONFLICTS=	gag-2*
NO_LATEST_LINK=	yes

do-install:
# Data
	@${MKDIR} ${DATADIR}
.for f in cdrom.iso disk.dsk
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor

# Documentation (optional)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in install.txt keyboard.txt uninstal.txt
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
