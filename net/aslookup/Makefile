PORTNAME=	aslookup
PORTVERSION=	0.13d
CATEGORIES=	net
MASTER_SITES=	http://aslookup.bgpview.org/download/ \
		https://BSDforce.com/source/net/aslookup/
DISTNAME=	${PORTNAME}-beta${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tool that searches the sequence of AS numbers

CFLAGS+=	-DARINDB -DJPNICDB -DAPNICDB

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aslookup ${STAGEDIR}${PREFIX}/bin
	@if [ ! -d ${STAGEDIR}${PREFIX}/share/doc/aslookup ]; then \
		${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/aslookup; fi
	${INSTALL_DATA} ${WRKSRC}/readme-eng.txt ${WRKSRC}/readme-jp.txt \
		${STAGEDIR}${PREFIX}/share/doc/aslookup

.include <bsd.port.mk>
