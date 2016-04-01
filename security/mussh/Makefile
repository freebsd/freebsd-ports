# Created by: Yen-Ming Lee <leeym@leeym.com>
# $FreeBSD$

PORTNAME=	mussh
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for easily running the same commands on multiple hosts

RUN_DEPENDS=	bash:shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		shebangfix tar:tgz
SHEBANG_FILES=	${WRKSRC}/${PORTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	BUGS CHANGES EXAMPLES README
PLIST_FILES=	bin/mussh

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s,seq 1 ,jot 1 ,g" \
		${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
