# New ports collection makefile for:	glbiff
# Date created:				18 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	glbiff
PORTVERSION=	0.3.5
CATEGORIES=	mail
MASTER_SITES=	http://www.dgp.utoronto.ca/~mac/projects/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes

MAN1=		glbiff.1
MAN5=		glbiffrc.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glbiff ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/glbiff.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/glbiffrc.5 ${PREFIX}/man/man5
	@${MKDIR} ${PREFIX}/share/examples/glbiff
	${INSTALL_DATA} ${WRKSRC}/glbiffrc.sample ${PREFIX}/share/examples/glbiff/dot.glbiffrc.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/glbiff
.for file in ChangeLog README README.last-minute TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/glbiff
.endfor
.endif

.include <bsd.port.mk>
