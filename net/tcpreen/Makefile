PORTNAME=	tcpreen
PORTVERSION=	1.4.4
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://www.remlab.net/files/tcpreen/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Simple TCP session re-engineering tool
WWW=		https://www.remlab.net/tcpreen/

LICENSE=	GPLv2+

USES=		cpe tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

OPTIONS_SUB=	yes

PORTDOCS=	AUTHORS NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS NLS

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
