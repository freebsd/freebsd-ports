# Created by: Nikolay Pavlov <qpadla@gmail.com>
# $FreeBSD$

PORTNAME=	openfire
PORTVERSION=	3.9.1
PORTEPOCH=	1
CATEGORIES=	net-im java
MASTER_SITES=	http://download.igniterealtime.org/openfire/
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/./_/g}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Enterprise instant messaging server

LICENSE=	APACHE20

RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper \
   		${JAVAJARDIR}/slf4j-api.jar:${PORTSDIR}/devel/slf4j

OPTIONS_DEFINE=	DOCS PLUGINS
OPTIONS_DEFAULT=PLUGINS
PLUGINS_DESC=	Install bundled plugins

USES=		dos2unix zip
DOS2UNIX_FILES=	src/java/org/jivesoftware/openfire/server/ServerDialback.java
USE_LDCONFIG=	yes
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+

CONFLICTS=	wildfire-[0-9]*

ALL_TARGET=	openfire
USE_RC_SUBR=	openfire
SUB_FILES+=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}_src
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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLUGINS}
ALL_TARGET+=	plugins
PLIST_SUB+=	PLUGINS=""
.else
PLIST_SUB+=	PLUGINS="@comment "
.endif

post-patch:
	(cd ${WRKSRC} && ${MV} \
	    ./src/plugins/jingleNodes/src/i18n/jingleNodes_i18n.properties \
	    ./src/plugins/jingleNodes/src/i18n/jinglenodes_i18n.properties)

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${MKDIR} ${STAGEDIR}${VARLOG}
	@${MKDIR} ${STAGEDIR}${VARDB}
	@${MKDIR} ${STAGEDIR}${ETCDIR}

	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 *.jar ${STAGEDIR}${DATADIR}/lib)
	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 log4j.xml ${STAGEDIR}${DATADIR}/lib)

	(cd ${INSTALL_WRKSRC}/resources && ${FIND} . \! -path ./security\* \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/resources)

#	always install admin interface
	(cd ${INSTALL_WRKSRC}/plugins/admin && ${FIND} . \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/plugins/admin)

.if ${PORT_OPTIONS:MPLUGINS}
	(cd ${INSTALL_WRKSRC}/plugins && ${FIND} . \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DATADIR}/plugins)
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} LICENSE.html README.html changelog.html \
	    ${STAGEDIR}${DOCSDIR})

	(cd ${WRKSRC}/documentation/docs && ${FIND} . \! -path ./javadoc\* \
	| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR} > /dev/null 2>&1 )
.endif
	${LN} -sf ${VARLOG} ${STAGEDIR}${DATADIR}/logs
	${LN} -sf ${VARDB}  ${STAGEDIR}${DATADIR}/embedded-db
	${LN} -sf ${ETCDIR} ${STAGEDIR}${DATADIR}/conf
	${LN} -sf ${ETCDIR} ${STAGEDIR}${DATADIR}/resources/security

	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/openfire.xml \
		${STAGEDIR}${ETCDIR}/openfire.xml.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/truststore \
		${STAGEDIR}${ETCDIR}/truststore.sample
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/keystore \
		${STAGEDIR}${ETCDIR}/keystore.sample

.include <bsd.port.mk>
