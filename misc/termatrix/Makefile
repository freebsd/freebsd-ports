# Ports collection makefile for:  termatrix
# Date created:                   2007/07/30
# Whom:                           chinsan
#
# $FreeBSD$
#

PORTNAME=	termatrix
PORTVERSION=	0.2
CATEGORIES=	misc
MASTER_SITES=	LOCAL/chinsan \
		http://lightless.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulates Matrix terminal's "green tears" effect

PLIST_FILES=	bin/termatrix
PORTDOCS=	README

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} -o ${WRKSRC}/termatrix \
		${WRKSRC}/termatrix.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/termatrix ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
