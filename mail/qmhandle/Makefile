PORTNAME=	qmhandle
PORTVERSION=	1.3.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-1.3/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to view and manage a qmail queue

LICENSE=	GPLv2

USES=		qmail:run perl5 tar:bzip2 shebangfix
SHEBANG_FILES=	qmHandle

NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	HISTORY README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
			  -e '/^##* *USER *CONFIGURATION *BEGIN *##*$$/,/^##* *USER *CONFIGURATION *END *##*$$/s/^\(#*\)my/\1our/g' \
		${WRKSRC}/qmHandle
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},g' ${FILESDIR}/qmHandle.conf.in > \
		${WRKSRC}/qmHandle.conf.sample

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmHandle ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/qmHandle.conf.sample ${STAGEDIR}${PREFIX}/etc

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
