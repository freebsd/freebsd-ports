# Created by: mharo@FreeBSD.org
# $FreeBSD$

PORTNAME=	keyprint
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	LOCAL/mharo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print S/Key keys on a piece of paper, twice the size of a credit card

USES=		shebangfix
NO_BUILD=	yes

PORTDOCS=	README
SHEBANG_FILES=	keyprint

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's,__PREFIX__,${PREFIX},' ${WRKSRC}/keyprint

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/keyblank.ps ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/keyprint ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
