# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	ipfw2dshield
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	http://www.dynamical-systems.org/ipfw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DShield client for ipfw logs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

PORTDOCS=	CHANGES README.html README.txt

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ipfw2dshield
	@${REINPLACE_CMD} -E -e '/^(CC|CFLAGS|prefix)/ s|=|?=|' \
		-e 's|bindir)|DESTDIR)$$(&|' \
		${WRKSRC}/ipaddr/Makefile \
		${WRKSRC}/strpdate/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
