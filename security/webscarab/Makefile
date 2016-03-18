# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	webscarab
PORTVERSION=	20090427
CATEGORIES=	security www java
MASTER_SITES=	LOCAL/niels \
		http://people.freebsd.org/~niels/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for analysing HTTP and HTTPS web application traffic

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}-1304
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PORTDOCS=	README LICENSE ChangeLog

OPTIONS_DEFINE=	DOCS

post-extract:
	${RM} ${WRKSRC}/lib/W32WinInet.dll

pre-install:
	@${SED} -e 's:%%PATH%%:${DATADIR}/:' \
		-e 's:%%JAVA_CMD%%:${JAVA}:' \
		-e 's:%%WEBSCARAB%%:${DATADIR}/${PORTNAME}.jar:' \
		< ${FILESDIR}/${PORTNAME}.sh > ${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/* ${STAGEDIR}${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}_lite

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
