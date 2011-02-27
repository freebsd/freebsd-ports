# New ports collection makefile for:	gag
# Date created:				12 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	gag
PORTVERSION=	4.9
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical Boot Manager

DEPRECATED=	no point in having it as a port, can be downloaded from the website and burned
EXPIRATION_DATE=	2011-04-11

ONLY_FOR_ARCHS=	i386 amd64 ia64
USE_ZIP=	yes
NO_BUILD=	yes

# security/gag
CONFLICTS=	gag-2*
NO_LATEST_LINK=	yes

do-install:
	${MKDIR} ${DATADIR}
.for f in cdrom.iso disk.dsk
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
