PORTNAME=	proxycheck
DISTVERSION=	0.49a
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.corpit.ru/mjt/proxycheck/ \
		http://www.it.ca/~paul/src/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Check for open proxy servers
WWW=		https://www.corpit.ru/mjt/proxycheck.html

DEPRECATED=	dnsbl.org has been shut down
EXPIRATION_DATE=	2026-07-31

PORTSCOUT=	skipv:0.49

HAS_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/proxycheck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/proxycheck.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
