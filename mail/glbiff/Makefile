# New ports collection makefile for:	glbiff
# Version required:			0.2.11
# Date created:				18 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=	glbiff-0.2.11
CATEGORIES=	mail
MASTER_SITES=	http://www.eecg.utoronto.ca/~mac/projects/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	GL:${PORTSDIR}/graphics/Mesa3 \
		GLU:${PORTSDIR}/graphics/Mesa3 \
		glut:${PORTSDIR}/graphics/Mesa3

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/glbiff ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/examples/glbiff
	@ ${INSTALL_DATA} ${WRKSRC}/glbiffrc.sample ${PREFIX}/share/examples/glbiff/dot.glbiffrc.sample

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/glbiff
.for file in ChangeLog README README.last-minute TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/glbiff
.endfor
.endif

.include <bsd.port.mk>
