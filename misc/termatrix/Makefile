# Created by: chinsan
# $FreeBSD$

PORTNAME=	termatrix
PORTVERSION=	0.2
CATEGORIES=	misc
MASTER_SITES=	LOCAL/chinsan \
		http://lightless.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulates Matrix terminal's "green tears" effect

LICENSE=	GPLv2

PLIST_FILES=	bin/termatrix
PORTDOCS=	README

do-build:
	${CC} ${CFLAGS} ${CPPFLAGS} -o ${WRKSRC}/termatrix \
		${WRKSRC}/termatrix.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/termatrix ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
