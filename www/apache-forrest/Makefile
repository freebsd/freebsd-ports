# Created by: nivit@users.sourceforge.net
# $FreeBSD$

PORTNAME=		apache-forrest
PORTVERSION=		0.9
PORTREVISION=		0
CATEGORIES=		www java
MASTER_SITES=		SITE_APACHE/forrest
DISTFILES=		${DISTNAME}-sources.tar.gz \
			${DISTNAME}-dependencies.tar.gz

MAINTAINER=		nivit@FreeBSD.org
COMMENT=		Tool for rapid development of small sites

BROKEN=		unfetchable

BROKEN_armv6=		fails to compile: build.xml: tools/ant/lib not found
BROKEN_armv7=		fails to compile: build.xml: tools/ant/lib not found

ANT=			${STAGEDIR}${DATADIR}/tools/ant/bin/ant
ANT_TARGET=		local-deploy

IGNORE_FILES=		! -name *\.bak -and ! -name *\.bat \
			-and ! -name *\.orig -and ! -name .gitignore \
			-and ! -name KEYS -and ! -name README.txt \
			-and ! -name ant -and ! -name forrest \
			-and ! -name index.html

INSTALL_WRKSRC=		${WRKSRC}/build

NO_BUILD=		Yes

PLUGINSDIR=		${DATADIR}/plugins/org.apache.forrest.plugin.output.pdf

REPLACE_FILES=		${WRKSRC}/bin/forrest ${WRKSRC}/tools/ant/bin/ant

SUB_FILES=		pkg-message
SUB_LIST=		PORTVERSION=${PORTVERSION}

USE_JAVA=		yes

post-patch:
	@for FILE in ${REPLACE_FILES}; do \
		${REINPLACE_CMD} -e "/%%JAVA_HOME%%/s//${JAVA_HOME:S/\//\\\//g}/g" \
		$${FILE} ;\
	done;

do-install:
	@cd ${WRKSRC}; \
	${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} '${IGNORE_FILES}'
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/forrest ${STAGEDIR}${DATADIR}/bin/forrest
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/ant/bin/ant ${STAGEDIR}${DATADIR}/tools/ant/bin/ant
	@${LN} -sf ../${DATADIR_REL}/bin/forrest ${STAGEDIR}${PREFIX}/bin/forrest
	@cd ${STAGEDIR}${PLUGINSDIR}; \
	${SETENV} FORREST_HOME=${STAGEDIR}${DATADIR} ${ANT} ${ANT_TARGET}

.include <bsd.port.mk>
