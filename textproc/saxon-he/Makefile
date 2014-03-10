# Created by: Herve Quiroz <herve.quiroz@esil.univ-mrs.fr>
# $FreeBSD$

PORTNAME=	saxon-he
PORTVERSION=	9.3.0.5
PORTREVISION=	1
CATEGORIES=	textproc java
MASTER_SITES=	SF/saxon/Saxon-HE/9.3
DISTNAME=	saxonhe${PORTVERSION:S,.,-,g}j.zip \
		saxon-resources9-3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XSLT 2.0 / XPath 2.0 / XQuery 1.0 processor for Java

LICENSE=	MPL

RUN_DEPENDS=	java:${PORTSDIR}/java/javavmwrapper

USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

JARFILES=	saxon9he.jar
PLIST_FILES+=	${JARFILES:S,^,%%DATADIR%%/,} bin/saxon-he bin/saxon-he-xquery
PLIST_DIRS+=	%%DATADIR%%
.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif
.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
.endif

SUB_FILES=	saxon.sh
SUB_LIST=	SAXON_JARS="${JARFILES:S,^,${DATADIR}/,}"

NO_STAGE=	yes
do-install:
	@${ECHO_MSG} -n ">> Installing JARs in ${DATADIR}/..."
	@${MKDIR} ${DATADIR}
.for file in ${JARFILES}
	@${ECHO_MSG} -n " ${file}"
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}/
.endfor
	@${ECHO_MSG} " [ DONE ]"
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} -n ">> Installing samples in ${EXAMPLESDIR}/..."
	@cd ${WRKSRC}/samples/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} -n ">> Installing documentation in ${DOCSDIR}/..."
	@cd ${WRKSRC}/doc/ \
	  && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \; \
	  && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	@${ECHO_MSG} " [ DONE ]"
.endif
	@${ECHO_MSG} -n ">> Installing scripts in ${PREFIX}/bin..."
.for scriptfile in saxon-he saxon-he-xquery
	@${ECHO_MSG} -n " ${scriptfile}"
	@${INSTALL_SCRIPT} ${WRKSRC}/saxon.sh ${PREFIX}/bin/${scriptfile}
.endfor
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
