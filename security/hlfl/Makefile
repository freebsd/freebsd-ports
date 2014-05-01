# Created by: Arnaud Launay <alaunay@hlfl.org>
# $FreeBSD$

PORTNAME=	hlfl
PORTVERSION=	0.60.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.hlfl.org/pub/hlfl/

MAINTAINER=	alaunay@hlfl.org
COMMENT=	High Level Firewall Language

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--datadir=${LOCALBASE}/share/doc
PORTDOCS=	services.hlfl sample_1.hlfl sample_2.hlfl test.hlfl syntax.txt
PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/hlfl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
