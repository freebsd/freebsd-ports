# New ports collection makefile for:	apache-forrest
# Date created:				14 October 2003
# Whom:					nivit@users.sourceforge.net
#
# $FreeBSD$

PORTNAME=		apache-forrest
PORTVERSION=		0.7
CATEGORIES=		www java
MASTER_SITES=		${MASTER_SITE_APACHE} \
			http://mirror.tomato.it/apache/forrest/ \
			http://mirrors.publicshout.org/apache/forrest/ \
			http://mirror.nohup.it/apache/forrest/ \
			http://www.apache.inetcosmos.org/dist/forrest/ \
			ftp://mirror.nohup.it/apache/forrest/
MASTER_SITE_SUBDIR=	forrest
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		nivit@users.sourceforge.net
COMMENT=		A tool for rapid development of small sites

USE_JAVA=		yes
JAVA_VERSION=		1.4+

USE_REINPLACE=		Yes
REPLACE_FILES=		${WRKSRC}/bin/forrest ${WRKSRC}/tools/ant/bin/ant

NO_BUILD=		Yes

INSTALL_WRKSRC=		${WRKSRC}/build
LINK_OPTS?=		-sf

FIND_ARGS1=		-type d \! -empty
FIND_ARGS2=		\! -type d -and -perm -a+x -and \! -name "*.orig" -and \! -name "*.bak"
FIND_ARGS3=		\! -type d -and \! -perm -a+x -and \! -name "*.bat" -and \! -name "*.orig" -and \! -name "LICENSE.txt" -and \! -name "KEYS" -and \! -name "NOTICE.txt" -and \! -name "*.license.txt"

ANT=		${DATADIR}/tools/ant/bin/ant
ANT_TARGET=	local-deploy
PLUGINSDIR=	${DATADIR}/plugins/org.apache.forrest.plugin.output.pdf

post-patch:
	@for FILE in ${REPLACE_FILES}; do \
		${REINPLACE_CMD} -e "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/g" \
		$${FILE} ;\
	done;

do-install:
# Script and data
	@cd ${WRKSRC}; \
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

# Links to executables
	@cd ${WRKSRC}; \
	FILES=$$(${FIND} bin ${FIND_ARGS2} ); \
	for FILE in $${FILES}; do \
		${LN} ${LINK_OPTS} ${DATADIR}/$${FILE} ${PREFIX}/$${FILE}; \
	done;

post-install:
	@cd ${PLUGINSDIR}; \
	${SETENV} FORREST_HOME=${DATADIR} ${ANT} ${ANT_TARGET}; \
	${SED} -e "/%%DATADIR%%/s//${DATADIR:S/\//\\\//g}/g" \
		-e "/%%PORTVERSION%%/s//${PORTVERSION}/g" ${PKGMESSAGE};

.include <bsd.port.mk>
