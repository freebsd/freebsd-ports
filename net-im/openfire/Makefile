# New ports collection makefile for:    openfire
# Date created:                         2006-11-12
# Whom:                                 Nikolay Pavlov <qpadla@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	openfire
PORTVERSION=	3.7.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net-im java
MASTER_SITES=	http://download.igniterealtime.org/openfire/
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/./_/g}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Enterprise instant messaging server

RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper \
   		${JAVAJARDIR}/slf4j-api.jar:${PORTSDIR}/devel/slf4j

USE_ZIP=	yes
USE_LDCONFIG=	yes
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

CONFLICTS=	wildfire-[0-9]*

ALL_TARGET=	openfire plugins
USE_RC_SUBR=	openfire

WRKSRC=		${WRKDIR}/${PORTNAME}_src
BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${WRKSRC}/target/openfire
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
VARLOG=		/var/log/openfire
VARDB=		/var/db/openfire
USERS=		openfire
GROUPS=		${USERS}

do-install:

	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 *.jar  ${JAVAJARDIR})
	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 log4j.xml  ${JAVAJARDIR})

	${MKDIR} ${DATADIR}
	${MKDIR} ${VARLOG}
	${MKDIR} ${VARDB}

	(cd ${INSTALL_WRKSRC}/resources && ${FIND} . \! -path ./security\* \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/resources)

	(cd ${INSTALL_WRKSRC}/plugins && ${FIND} . \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/plugins)

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} \
	LICENSE.html README.html changelog.html ${DOCSDIR})

	(cd ${WRKSRC}/documentation/docs && ${FIND} . \! -path ./javadoc\* \
	| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1 )
.endif

post-install:

	${LN} -sf ${VARLOG} ${DATADIR}/logs
	${LN} -sf ${VARDB}  ${DATADIR}/embedded-db
	${LN} -sf ${ETCDIR} ${DATADIR}/conf
	${LN} -sf ${ETCDIR} ${DATADIR}/resources/security

	${MKDIR} ${EXAMPLESDIR}

	${INSTALL_DATA} ${INSTALL_WRKSRC}/conf/openfire.xml \
		${EXAMPLESDIR}/openfire.xml
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/truststore \
		${EXAMPLESDIR}/truststore
	${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/keystore \
		${EXAMPLESDIR}/keystore
	@if [ ! -f ${ETCDIR}/openfire.xml ]; then \
		${MKDIR} ${ETCDIR}; \
		${INSTALL} -m 644 ${INSTALL_WRKSRC}/conf/openfire.xml \
		${ETCDIR}/openfire.xml; \
	fi
	@if [ ! -f ${ETCDIR}/keystore ]; then \
		${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/keystore \
		${ETCDIR}/keystore; \
	fi
	@if [ ! -f ${ETCDIR}/truststore ]; then \
		${INSTALL} -m 600 ${INSTALL_WRKSRC}/resources/security/truststore \
		${ETCDIR}/truststore; \
	fi

	${CHOWN} -Rh ${USERS}:${GROUPS} ${ETCDIR}
	${CHOWN} -Rh ${USERS}:${GROUPS} ${VARDB}
	${CHOWN} -Rh ${USERS}:${GROUPS} ${VARLOG}
	${CHOWN} -Rh ${USERS}:${GROUPS} ${DATADIR}

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
