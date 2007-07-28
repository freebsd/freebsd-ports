# New ports collection makefile for:    openfire
# Date created:                         2006-11-12
# Whom:                                 Nikolay Pavlov <quetzal@zone3000.net>
#
# $FreeBSD$
#

PORTNAME=	openfire
PORTVERSION=	3.3.2
CATEGORIES=	net-im java
MASTER_SITES=	http://www.igniterealtime.org/downloadServlet?filename=openfire/
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/./_/g}

MAINTAINER=	quetzal@zone3000.net
COMMENT=	Openfire (formerly Wildfire) is an enterprise instant messaging server

RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper

USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

CONFLICTS=	wildfire-[0-9]*

ALL_TARGET=	openfire
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

MLINKS=		${VARLOG} ${DATADIR}/logs \
		${VARDB} ${DATADIR}/embedded-db \
		${ETCDIR} ${DATADIR}/conf \
		${ETCDIR} ${DATADIR}/resources/security

do-install:

	(cd ${INSTALL_WRKSRC}/lib && \
	${INSTALL_DATA} -m 744 *.jar ${JAVAJARDIR});

	${MKDIR} ${DATADIR};
	${MKDIR} ${VARLOG};
	${MKDIR} ${VARDB};

	(cd ${INSTALL_WRKSRC}/resources && ${FIND} . \! -path ./security\* \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/resources)

	(cd ${INSTALL_WRKSRC}/plugins && ${FIND} . \
	| ${CPIO} -pvdmu -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}/plugins)

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR};
	(cd ${WRKSRC} && ${INSTALL_DATA} -o ${SHAREOWN} -g ${SHAREGRP} \
	LICENSE.html README.html changelog.html ${DOCSDIR});

	(cd ${WRKSRC}/documentation/docs && ${FIND} . \
	| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR} > /dev/null 2>&1 )
.endif

post-install:
	${MKDIR} ${EXAMPLESDIR};
	${CP} -p ${INSTALL_WRKSRC}/conf/openfire.xml ${EXAMPLESDIR}/openfire.xml
	${CP} -p ${INSTALL_WRKSRC}/resources/security/truststore \
		${EXAMPLESDIR}/truststore
	${CP} -p ${INSTALL_WRKSRC}/resources/security/keystore \
		${EXAMPLESDIR}/keystore
	@if [ ! -f ${ETCDIR}/openfire.xml ]; then \
		${MKDIR} ${ETCDIR}; \
		${CP} -p ${INSTALL_WRKSRC}/conf/openfire.xml ${ETCDIR}/openfire.xml; \
	fi
	@if [ ! -f ${ETCDIR}/keystore ]; then \
		${CP} -p ${INSTALL_WRKSRC}/resources/security/keystore \
			${ETCDIR}/keystore; \
	fi
	@if [ ! -f ${ETCDIR}/truststore ]; then \
		${CP} -p ${INSTALL_WRKSRC}/resources/security/truststore \
			${ETCDIR}/truststore; \
	fi
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${CHOWN} -R ${PUSER}:${PGROUP} ${ETCDIR}
	${CHOWN} -R ${PUSER}:${PGROUP} ${VARDB}
	${CHOWN} -R ${PUSER}:${PGROUP} ${VARLOG}
	${CHOWN} -R ${PUSER}:${PGROUP} ${DATADIR}

	@${ECHO_CMD} "===> post-installation information for ${PKGNAME}:"
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.mk>
