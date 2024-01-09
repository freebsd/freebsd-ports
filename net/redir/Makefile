PORTNAME=	redir
PORTVERSION=	2.2.1
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://sammy.net/~sammy/hacks/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TCP connection redirection utility
WWW=		https://sammy.net/~sammy/hacks/

USES=		gmake
USE_RC_SUBR=	redir

PLIST_FILES=	bin/redir share/man/man1/redir.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/redir ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/redir.man ${STAGEDIR}${PREFIX}/share/man/man1/redir.1

.include <bsd.port.mk>
