PORTNAME=	redir
PORTVERSION=	2.2.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://sammy.net/~sammy/hacks/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP connection redirection utility

USES=		gmake
USE_RC_SUBR=	redir

PLIST_FILES=	bin/redir man/man1/redir.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/redir ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/redir.man ${STAGEDIR}${MANPREFIX}/man/man1/redir.1

.include <bsd.port.mk>
