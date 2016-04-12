# Created by: Yoshiro MIHIRA <sanpei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thumbnail_index
PORTVERSION=	1998.08.10
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/thumbnail_index/
DISTNAME=	${PORTNAME}_10aug1998

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Make an HTML index file for a bunch of images

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	pnmscale:graphics/netpbm

USES=		jpeg:run
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/thumbnail_index ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/thumbnail_reap ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/thumbnail_index.1 ${STAGEDIR}${PREFIX}/man/man1/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
