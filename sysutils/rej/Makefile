# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	rej
PORTVERSION=	0.16
CATEGORIES=	sysutils perl5
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Merges patch-rejects and runs a merge program to verify the changes

USES=		shebangfix perl5
NO_BUILD=	yes

SHEBANG_FILES=	qp mp

PORTDOCS=	CHANGELOG README vimrc
PLIST_FILES=	bin/rej bin/rej-qp bin/rej-mp

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${SH}|' \
		${WRKSRC}/runtests.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.for f in qp mp
	${INSTALL_SCRIPT} ${WRKSRC}/${f} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${f}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

run-test: patch
	@cd ${WRKSRC}; ${SH} runtests.sh

.include <bsd.port.mk>
