# Created by: Niels Heinen
# $FreeBSD$

PORTNAME=	webscarab
PORTVERSION=	20090427
CATEGORIES=	security www java
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~niels/distfiles/
MASTER_SITE_SUBDIR=	niels

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Framework for analysing HTTP and HTTPS web application traffic

USES=		zip
USE_JAVA=	YES
JAVA_VERSION=	1.6+
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}-1304
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

PORTDOCS=	README LICENSE ChangeLog

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
	${RM} ${WRKSRC}/lib/W32WinInet.dll

pre-install:
	@${SED} -e 's:%%PATH%%:${DATADIR}/:' \
		-e 's:%%JAVA_CMD%%:${JAVA}:' \
		-e 's:%%WEBSCARAB%%:${DATADIR}/${PORTNAME}.jar:' \
		< ${FILESDIR}/${PORTNAME}.sh > ${WRKDIR}/${PORTNAME}

do-install:
	${MKDIR} ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DATADIR}/lib
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.jar ${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}_lite
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.       for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.       endfor
.endif

.include <bsd.port.post.mk>
