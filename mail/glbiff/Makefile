# New ports collection makefile for:	glbiff
# Version required:			0.2
# Date created:				18 May 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.1.1.1 1998/05/21 22:36:14 mph Exp $
#

DISTNAME=	glbiff-0.2
CATEGORIES=	mail x11
MASTER_SITES=	http://www.eecg.utoronto.ca/~mac/projects/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	MesaGL\\.13\\.:${PORTSDIR}/graphics/Mesa \
		MesaGLU\\.13\\.:${PORTSDIR}/graphics/Mesa \
		Mesatk\\.13\\.:${PORTSDIR}/graphics/Mesa \
		glut\\.3\\.:${PORTSDIR}/graphics/Mesa
RUN_DEPENDS=	elm:${PORTSDIR}/mail/elm

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
