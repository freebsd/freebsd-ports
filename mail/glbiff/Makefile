# New ports collection makefile for:	glbiff
# Version required:			0.2
# Date created:				18 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.7 1998/10/01 02:17:48 jseger Exp $
#

DISTNAME=	glbiff-0.2
CATEGORIES=	mail
MASTER_SITES=	http://www.eecg.utoronto.ca/~mac/projects/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	MesaGL.14:${PORTSDIR}/graphics/Mesa3 \
		MesaGLU.14:${PORTSDIR}/graphics/Mesa3 \
		Mesatk.14:${PORTSDIR}/graphics/Mesa3 \
		glut.3:${PORTSDIR}/graphics/Mesa3

BROKEN=		can\'t find mesatk

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
