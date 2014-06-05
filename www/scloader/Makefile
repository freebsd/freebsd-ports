# Created by: Radim Kolar <hsn@sanatana.dharma>
# $FreeBSD$

PORTNAME=	scloader
PORTVERSION=	0.32
CATEGORIES=	www java
MASTER_SITES=	SF
DISTNAME=	loader${PORTVERSION:C/\.//}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Configurable web graber/spider

USES=		dos2unix zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} %%JAVAJARDIR%%/scloader.jar
PORTDOCS=	README history todo

DOS2UNIX_REGEX=	.+\.[^j][^a][^r]$

do-configure:
		${SED} -e "s|%%JAVA%%|${LOCALBASE}/bin/java|" \
		-e "s|%%JAVAJARDIR%%|${JAVAJARDIR}|" \
		${FILESDIR}/${PORTNAME}.sh > ${WRKDIR}/${PORTNAME}

do-install:
		${INSTALL} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${JAVAJARDIR}
		${INSTALL_DATA} ${WRKSRC}/scloader.jar ${STAGEDIR}${JAVAJARDIR}
.ifndef	NOPORTDOCS
		${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
		${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/samples/loader.cnf ${STAGEDIR}${DOCSDIR}
PORTDOCS+=	manual.html loader.cnf
.endif

.include <bsd.port.mk>
