PORTNAME=	socket
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	sysutils net
MASTER_SITES=	https://wolfram.schneider.org/src/ LOCAL/wosch

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create TCP socket and connect to stdin/out

LICENSE=	GPLv1

MAKE_ARGS=	INSTALLMANPATH=${STAGEDIR}${PREFIX}/share/man

PLIST_FILES=	bin/socket share/man/man1/socket.1.gz

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
