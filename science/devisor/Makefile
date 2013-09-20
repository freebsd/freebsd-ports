# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	devisor
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	science java
MASTER_SITES=	http://www.featflow.de/download/
DISTNAME=	devisor${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Design and Visualization Software Resource for FeatFlow

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes	# Sources are available though

SUB_FILES=	devisorgrid.sh

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

DATAFILES=	data images misc manual
CLASSFILES=	devisor2 devisorgrid.class

PORTDOCS=	*
PLIST_FILES=	bin/devisorgrid

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/devisorgrid.sh ${PREFIX}/bin/devisorgrid
	cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -not -name '*.pdf' -print -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	cd ${WRKSRC} \
	  && ${FIND} ${CLASSFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${CLASSFILES} -name '*.class' -type f -print -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/manual \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -name '*.pdf' -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
.endif

post-install:
	@cd ${WRKSRC} \
	  && ${FIND} -s ${DATAFILES} -type f -not -name '*.pdf' \
	    | ${SED} -ne 's,^,${DATADIR:S,${PREFIX}/,,}/,p' >> ${TMPPLIST} \
	  && ${FIND} -s -d ${DATAFILES} -type d \
	    | ${SED} -ne 's,^,@dirrm ${DATADIR:S,${PREFIX}/,,}/,p' >> ${TMPPLIST}
	@cd ${WRKSRC} \
	  && ${FIND} -s ${CLASSFILES} -name '*.class' -type f \
	    | ${SED} -ne 's,^,${DATADIR:S,${PREFIX}/,,}/,p' >> ${TMPPLIST} \
	  && ${FIND} -s -d ${CLASSFILES} -type d \
	    | ${SED} -ne 's,^,@dirrm ${DATADIR:S,${PREFIX}/,,}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,${PREFIX}/,,}' >> ${TMPPLIST}

.include <bsd.port.mk>
