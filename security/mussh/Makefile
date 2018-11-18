# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	mussh
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Tool for easily running the same commands on multiple hosts

LICENSE=	GPLv2

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix tar:tgz

WRKSRC=		${WRKDIR}/${PORTNAME}

SHEBANG_FILES=	${WRKSRC}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	BUGS CHANGES EXAMPLES README
PLIST_FILES=	bin/mussh man/man1/mussh.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
