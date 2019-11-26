# Created by: KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fop
DISTVERSION=	2.3
CATEGORIES=	textproc java
MASTER_SITES=	APACHE/xmlgraphics/fop/source/:fop \
		SF/offo/offo-hyphenation/2.2:hyph # offo-hyphenation doesn't provide the corresponding version 2.3, 2.2 should be good for fop-2.3
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.tar.gz:fop offo-hyphenation.zip:hyph
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	geoff@sea-incorporated.com
COMMENT=	Print formatter driven by XSL formatting

LICENSE=	APACHE20
LICENSE_FILE=	${LEGALDIR}/LICENSE

EXTRACT_DEPENDS=	${UNZIP_CMD}:archivers/unzip

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}/fop
LEGALDIR=	${WRKDIR}/${DISTNAME:S/-src//}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PORTDOCS=	*

USE_JAVA=	yes
USE_ANT=	yes

NO_ARCH=	yes

# Prevent out of memory error during build
MAKE_ENV+=	"ANT_OPTS=-Xmx512m"

post-extract:
	@cd ${WRKDIR} && ${UNZIP_CMD} ${DISTDIR}/offo-hyphenation.zip
	@${CP} ${WRKDIR}/offo-hyphenation/hyph/*.xml ${WRKSRC}/hyph

do-install:
.for d in build conf lib
	@${MKDIR} ${STAGEDIR}${DATADIR}/${d}
.endfor
	@cd ${WRKSRC} && \
	    ${INSTALL_DATA} build/*.[jw]ar ${STAGEDIR}${DATADIR}/build && \
	    ${INSTALL_DATA} lib/*.jar lib/README.txt ${STAGEDIR}${DATADIR}/lib && \
	    ${INSTALL_DATA} conf/fop.xconf ${STAGEDIR}${DATADIR}/conf && \
	    ${COPYTREE_SHARE} hyph ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${LN} -s ../${DATADIR_REL}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${LEGALDIR} && ${INSTALL_DATA} README NOTICE KEYS ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
