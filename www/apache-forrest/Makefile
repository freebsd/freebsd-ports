# New ports collection makefile for:	apache-forrest
# Date created:				14 October 2003
# Whom:					nivit@users.sourceforge.net
#
# $FreeBSD$

PORTNAME=		apache-forrest
PORTVERSION=		0.5.1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_APACHE} \
			http://mirror.tomato.it/apache/forrest/ \
			http://mirrors.publicshout.org/apache/forrest/ \
			http://mirror.nohup.it/apache/forrest/ \
			http://www.apache.inetcosmos.org/dist/forrest/ \
			ftp://mirror.nohup.it/apache/forrest/
MASTER_SITE_SUBDIR=	forrest
DISTNAME=		${PORTNAME}-${PORTVERSION}-src

MAINTAINER=		nivit@users.sourceforge.net
COMMENT=		A tool for rapid development of small sites

USE_JAVA=		1.2+

REPLACE_FILES=		${WRKSRC}/src/resources/forrest-shbat/bin/forrest \
			${WRKSRC}/src/resources/forrestbot/bin/forrestbot

BUILD_CMD=		${SETENV} JAVA_HOME=${JAVA_HOME} ${WRKSRC}/build.sh

.if !defined(NOPORTDOCS)
BUILD_DOCS=		site
FORREST_DOCS=		${INSTALL_WRKSRC}/${BUILD_DOCS}
.endif

INSTALL_WRKSRC=		${WRKSRC}/build
FORREST_DIR=		${INSTALL_WRKSRC}/dist/shbat
LINK_OPTS?=		-sf

FIND_ARGS1=		-type d \! -empty
FIND_ARGS2=		\! -type d -and -perm -a+x -and \! -name "*.orig"
FIND_ARGS3=		\! -type d -and \! -perm -a+x -and \! -name "*.bat" -and \! -name "*.orig"

post-patch:
	@for FILE in ${REPLACE_FILES}; do \
		${SED} \
		-e "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/g" \
		$${FILE} > ${WRKSRC}/`basename $${FILE}`; \
		${MV} -f ${WRKSRC}/`basename $${FILE}` $${FILE}; \
	done;

do-build:
	@cd ${WRKSRC}; \
	${BUILD_CMD} ${BUILD_DOCS}

do-install:
# Script and data
	@cd ${FORREST_DIR}; \
	DIRS=$$(${FIND} . ${FIND_ARGS1}); \
	for DIR in $${DIRS}; do \
		${MKDIR} ${DATADIR}/$${DIR}; \
	done; \
	FILES=$$(${FIND} . ${FIND_ARGS2} ); \
	for FILE in $${FILES}; do \
		${INSTALL_SCRIPT} $${FILE} ${DATADIR}/$${FILE}; \
	done; \
	FILES=$$(${FIND} . ${FIND_ARGS3}); \
	for FILE in $${FILES}; do \
		${INSTALL_DATA} $${FILE} ${DATADIR}/$${FILE}; \
	done;
# Documentation
.if !defined(NOPORTDOCS)
	@cd ${FORREST_DOCS}; \
	DIRS=$$(${FIND} . ${FIND_ARGS1}); \
	for DIR in $${DIRS}; do \
		${MKDIR} ${DOCSDIR}/$${DIR}; \
	done; \
	FILES=$$(${FIND} . ${FIND_ARGS3}); \
	for FILE in $${FILES}; do \
		${INSTALL_DATA} $${FILE} ${DOCSDIR}/$${FILE}; \
	done;
.endif
# Links to executables
	@cd ${FORREST_DIR}; \
	FILES=$$(${FIND} bin ${FIND_ARGS2} ); \
	for FILE in $${FILES}; do \
		${LN} ${LINK_OPTS} ${DATADIR}/$${FILE} ${PREFIX}/$${FILE}; \
	done;

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
