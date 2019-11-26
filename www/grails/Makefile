# Created by: Mitchell Smith <mjs@bur.st>
# $FreeBSD$

PORTNAME=	grails
DISTVERSION=	1.3.6
CATEGORIES=	www java
MASTER_SITES=	http://dist.codehaus.org/grails/ \
		http://dist.springframework.org.s3.amazonaws.com/release/GRAILS/

MAINTAINER=	mjs@bur.st
COMMENT=	Web framework built on Groovy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:tu}

USES=		zip
USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	LICENSE README build.gradle build.properties gradle.properties \
		gradlew conf dist gradle lib media plugins scripts src
SCRIPTFILES=	grails grails-debug startGrails

OPTIONS_DEFINE=	DOCS

PORTDOCS=	api guide index.html css img ref
PLIST_FILES=	${SCRIPTFILES:S,^,bin/,} \
		${SCRIPTFILES:S,^,${DATADIR:S,${PREFIX}/,,}/bin/,}
SUB_FILES=	edit-startGrails.sed pkg-message

do-install:
	@${ECHO_MSG} -n ">> Installing data files in ${DATADIR}..."
	@cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing and symlinking executables..."
	@${MKDIR} ${STAGEDIR}${DATADIR}/bin
	@${REINPLACE_CMD} -f ${WRKDIR}/edit-startGrails.sed ${WRKSRC}/bin/startGrails
.for file in ${SCRIPTFILES}
	@${ECHO_MSG} -n " ${file}"
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${STAGEDIR}${DATADIR}/bin/${file}
	@${LN} -fs ${DATADIR}/bin/${file} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
	@${ECHO_MSG} " [ DONE ]"

do-install-DOCS-on:
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc \
	  && ${FIND} . -type d -exec ${MKDIR} ${STAGEDIR}${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}

.include <bsd.port.mk>
