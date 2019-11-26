# Created by: Radim Kolar <hsn@sanatana.dharma>
# $FreeBSD$

PORTNAME=	scloader
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	SF
DISTNAME=	loader${PORTVERSION:C/\.//}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Configurable web graber/spider

LICENSE=	GPLv2

USES=		dos2unix zip
USE_JAVA=	yes

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} %%JAVAJARDIR%%/scloader.jar

DOS2UNIX_REGEX=	.+\.[^j][^a][^r]$

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	README history todo manual.html
PORTEXAMPLES=	loader.cnf

do-configure:
		${SED} -e "s|%%JAVA%%|${LOCALBASE}/bin/java|" \
		-e "s|%%JAVAJARDIR%%|${JAVAJARDIR}|" \
		${FILESDIR}/${PORTNAME}.sh > ${WRKSRC}/${PORTNAME}

do-install:
		${INSTALL} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/scloader.jar ${STAGEDIR}${JAVAJARDIR}
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README history todo
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
		${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${STAGEDIR}${DOCSDIR}
		@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/samples/loader.cnf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
