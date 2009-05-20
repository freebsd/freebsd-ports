# New ports collection makefile for:	grails
# Date created:			2008-03-10
# Whom:				Mitchell Smith <mjs@bur.st>
#
# $FreeBSD$
#

PORTNAME=	grails
DISTVERSION=	1.1.1
CATEGORIES=	www java
MASTER_SITES=	http://dist.codehaus.org/grails/
DISTNAME=	${PORTNAME}-bin-${PORTVERSION}

MAINTAINER=	mjs@bur.st
COMMENT=	Web framework built on Groovy

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:U}

USE_JAVA=	yes
JAVA_VERSION=	1.4+
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	LICENSE build.properties build.xml ant conf dist media lib \
		scripts src
SCRIPTFILES=	grails grails-debug startGrails

.if !defined(NOPORTDOCS)
PORTDOCS=	api
.endif
PLIST_FILES=	${SCRIPTFILES:S,^,bin/,}
SUB_FILES=	set-grails_home.sed pkg-message

do-install:
	@${ECHO_MSG} -n ">> Installing data files in ${DATADIR}..."
	@cd ${WRKSRC} \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
	@${ECHO_MSG} -n ">> Installing executables in ${PREFIX}/bin..."
	@${REINPLACE_CMD} -f ${WRKDIR}/set-grails_home.sed ${WRKSRC}/bin/startGrails
.for file in ${SCRIPTFILES}
	@${ECHO_MSG} -n " ${file}"
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${PREFIX}/bin/
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}..."
	@cd ${WRKSRC}/doc \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif

post-install:
	@${FIND} -s ${DATAFILES:S,^,${WRKSRC}/,} -not -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${FIND} -s -d ${DATAFILES:S,^,${WRKSRC}/,} -type d 2>/dev/null | \
	  ${SED} -ne 's,^${WRKSRC},@dirrm ${DATADIR:S,^${PREFIX}/,,},p' >> ${TMPPLIST}
	@${ECHO_CMD} '@dirrm ${DATADIR:S,^${PREFIX}/,,}' >> ${TMPPLIST}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
