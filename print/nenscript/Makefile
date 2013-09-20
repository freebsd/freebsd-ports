# Created by: cjm2
# $FreeBSD$

PORTNAME=	nenscript
PORTVERSION=	1.13.3
CATEGORIES=	print
MASTER_SITES=	http://www.ai.mit.edu/projects/im/magnus/nenscript/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of the proprietary enscript program from Adobe Systems

USE_BZIP2=	yes

MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"
MAN1=		nenscript.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nenscript ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nenscript.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
