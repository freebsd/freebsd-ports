# New ports collection makefile for:	glbiff
# Version required:			0.2
# Date created:				18 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1998/07/11 00:28:05 steve Exp $
#

DISTNAME=	glbiff-0.2
CATEGORIES=	mail x11
MASTER_SITES=	http://www.eecg.utoronto.ca/~mac/projects/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	MesaGL\\.13\\.:${PORTSDIR}/graphics/Mesa2 \
		MesaGLU\\.13\\.:${PORTSDIR}/graphics/Mesa2 \
		Mesatk\\.13\\.:${PORTSDIR}/graphics/Mesa2 \
		glut\\.3\\.:${PORTSDIR}/graphics/Mesa2

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/glbiff

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/glbiff ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/examples/glbiff
	@ ${INSTALL_DATA} ${FILESDIR}/dot.glbiffrc.sample ${PREFIX}/share/examples/glbiff
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/glbiff
.for file in ChangeLog README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/glbiff
.endfor
.endif

.include <bsd.port.mk>
