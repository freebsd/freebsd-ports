# Created by: KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fop
PORTVERSION=	1.1
CATEGORIES=	textproc java
MASTER_SITES=	${MASTER_SITE_APACHE:S/$/:fop/} \
		SF/offo/offo-hyphenation/2.0:hyph
MASTER_SITE_SUBDIR=	xmlgraphics/fop/source/:fop
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}.tar.gz:fop offo-hyphenation_v2.0.zip:hyph
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	geoff@sea-incorporated.com
COMMENT=	Print formatter driven by XSL formatting

EXTRACT_DEPENDS+=	${UNZIP_CMD}:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
DATADIR=	${JAVASHAREDIR}/${PORTNAME}

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes

# Prevent out of memory error during build
MAKE_ENV+=	"ANT_OPTS=-Xmx512m"

NO_STAGE=	yes
post-extract:
	@cd ${WRKDIR} && ${UNZIP_CMD} ${DISTDIR}/offo-hyphenation_v2.0.zip
	@${CP} ${WRKDIR}/offo-hyphenation/hyph/*.xml ${WRKSRC}/hyph

do-install:
.for d in build conf lib
	@${MKDIR} ${DATADIR}/${d}
.endfor
	@cd ${WRKSRC} && \
	    ${INSTALL_DATA} status.xml ${DATADIR}/ && \
	    ${INSTALL_DATA} build/*.[jw]ar ${DATADIR}/build/ && \
	    ${INSTALL_DATA} lib/*.jar lib/README.txt ${DATADIR}/lib/ && \
	    ${INSTALL_DATA} conf/fop.xconf ${DATADIR}/conf/ && \
	    ${COPYTREE_SHARE} hyph ${DATADIR}/
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${DATADIR}/
	@${LN} -s ${DATADIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_MAN} LICENSE README NOTICE KEYS ${DOCSDIR}
.endif

.include <bsd.port.mk>
