# Created by: mharo@FreeBSD.org
# $FreeBSD$

PORTNAME=	keyprint
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	LOCAL/mharo

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Print S/Key keys on a piece of paper, twice the size of a credit card

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	keyprint
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,__PREFIX__,${PREFIX},' ${WRKSRC}/keyprint

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keyprint ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/keyblank.ps ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
