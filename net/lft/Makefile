# Created by: Marco P. Rodrigues <drkangel@drkangel.org>
# $FreeBSD$

PORTNAME=	lft
PORTVERSION=	3.33
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://pwhois.org/get/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Layer 4 Traceroute program

GNU_CONFIGURE=	yes

PLIST_FILES=	sbin/lft bin/whob man/man8/lft.8.gz man/man8/whob.8.gz
PORTDOCS=	CHANGELOG README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lft ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/whob ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/lft.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/whob.8 ${STAGEDIR}${MANPREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
