PORTNAME=	proxycheck
PORTVERSION=	0.49a
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/ \
		http://www.it.ca/~paul/src/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Check for open proxy servers
WWW=		https://www.corpit.ru/mjt/proxycheck.html

PORTSCOUT=	skipv:0.49

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
