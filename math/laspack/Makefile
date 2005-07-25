# New ports collection makefile for:    LASPack
# Date created:         27 July 2005
# Whom: 		giffunip
#
# $FreeBSD$
#

PORTNAME=	laspack
PORTVERSION=	1.12.2
CATEGORIES=	math
MASTER_SITES=	ftp://netlib.bell-labs.com/netlib/linalg/	\
		ftp://www.hensa.ac.uk/mirrors/netlib/linalg/	\
		http://www.netlib.org/linalg/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	giffunip@asme.org
COMMENT=	Package for solving large sparse systems of linear equations

USE_REINPLACE=	yes
WRKSRC=	${WRKDIR}/${PORTNAME}
MAKEFILE=	makefile

post-patch:
	@${REINPLACE_CMD} -e 's+/usr/local+${LOCALBASE}+g' ${WRKSRC}/${MAKEFILE}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
