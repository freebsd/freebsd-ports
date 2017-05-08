# Created by: Nikolay Pavlov <qpadla@gmail.com>
# $FreeBSD$

PORTNAME=	openfire
PORTVERSION=	4.1.4
DISTVERSIONPREFIX=	v
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	net-im java

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Enterprise instant messaging server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	slf4j>=1.7.7:devel/slf4j

USE_GITHUB=	yes
GH_ACCOUNT=	igniterealtime
GH_PROJECT=	Openfire

OPTIONS_DEFINE=	DOCS PLUGINS
OPTIONS_DEFAULT=PLUGINS
OPTIONS_SUB=	yes
PLUGINS_DESC=	Install bundled plugins

USES=		cpe dos2unix
DOS2UNIX_FILES=	src/java/org/jivesoftware/openfire/server/ServerDialback.java
USE_LDCONFIG=	yes
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.8
NO_ARCH=	yes

CPE_VENDOR=	igniterealtime

ALL_TARGET=	openfire
USE_RC_SUBR=	openfire
SUB_FILES+=	pkg-message

BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${WRKSRC}/target/openfire
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
PORTDOCS=	*
VARLOG=		/var/log/openfire
VARDB=		/var/db/openfire
USERS=		openfire
GROUPS=		${USERS}
PLIST_SUB+=	VARLOG=${VARLOG} \
		VARDB=${VARDB}

PLUGINS_ALL_TARGET=	plugins

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${MKDIR} ${STAGEDIR}${VARDB}
	@${MKDIR} ${STAGEDIR}${VARLOG}

	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 *.jar ${STAGEDIR}${DATADIR}/lib)
	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 log4j.xml ${STAGEDIR}${DATADIR}/lib)

	(cd ${INSTALL_WRKSRC}/resources && \
	    ${FIND} . \! -path ./security\* \! -path ./nativeAuth\* | \
	    ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} \
	        ${STAGEDIR}${DATADIR}/resources)

#	always install admin interface
	(cd ${INSTALL_WRKSRC}/plugins/admin && ${FIND} . \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/plugins/admin)

	${LN} -sf ${ETCDIR} ${STAGEDIR}${DATADIR}/conf
	${LN} -sf ${ETCDIR} ${STAGEDIR}${DATADIR}/resources/security
	${LN} -sf ${VARDB} ${STAGEDIR}${DATADIR}/embedded-db
	${LN} -sf ${VARLOG} ${STAGEDIR}${DATADIR}/logs
	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/openfire.xml \
		${STAGEDIR}${ETCDIR}/openfire.xml.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/truststore \
		${STAGEDIR}${ETCDIR}/truststore.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/keystore \
		${STAGEDIR}${ETCDIR}/keystore.sample
	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/security.xml \
		${STAGEDIR}${ETCDIR}/security.xml.sample

do-install-PLUGINS-on:
	(cd ${INSTALL_WRKSRC}/plugins && ${FIND} . \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/plugins)

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/documentation/docs && ${FIND} . \! -path ./javadoc\* \
	| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1 )

.include <bsd.port.mk>
