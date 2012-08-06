# New ports collection makefile for:    openfire-devel
# Date created:                         24 January 2011
# Whom:                                 gahr
#
# $FreeBSD$
#

PORTNAME=	openfire
DISTVERSION=	3.7.0.beta
CATEGORIES=	net-im java
MASTER_SITES=	http://www.igniterealtime.org/downloadServlet?filename=openfire/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}_src_${DISTVERSION:S/./_/g}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Enterprise instant messaging server (development version)

IGNORE=		No development version available right now. Please use net-im/openfire instead.

RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper

CONFLICTS=	openfire-[0-9]*

USE_LDCONFIG=	yes
USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

CONFLICTS=	wildfire-[0-9]*

ALL_TARGET=	openfire plugins
USE_RC_SUBR=	openfire
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}_src
BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${WRKSRC}/target/openfire
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
VARLOG=		/var/log/openfire
VARDB=		/var/db/openfire
PUSER=		openfire
PGROUP=		${PUSER}

do-install:

	(cd ${INSTALL_WRKSRC}/lib && ${INSTALL} -m 744 *.jar ${JAVAJARDIR})

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
	${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

	${CHOWN} -Rh ${PUSER}:${PGROUP} ${ETCDIR}
	${CHOWN} -Rh ${PUSER}:${PGROUP} ${VARDB}
	${CHOWN} -Rh ${PUSER}:${PGROUP} ${VARLOG}
	${CHOWN} -Rh ${PUSER}:${PGROUP} ${DATADIR}

	@${ECHO_CMD} "===> post-installation information for ${PKGNAME}:"
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.mk>
