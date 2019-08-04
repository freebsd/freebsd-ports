# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	poppy
PORTVERSION=	4.01
CATEGORIES=	mail
MASTER_SITES=	http://www.cnpbagwell.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client to perform simple tasks with a POP3/IMAP server

BROKEN=		unfetchable

USES=		shebangfix
NO_BUILD=	yes

SHEBANG_FILES=	poppy spamkill

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/poppy ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/spamkill ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/poppy.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
