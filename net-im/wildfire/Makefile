# New ports collection makefile for:    wildfire
# Date created:                         2006-11-12
# Whom:                                 Nikolay Pavlov <quetzal@zone3000.net>
#
# $FreeBSD$
#

PORTNAME=	wildfire
PORTVERSION=	3.2.4
PORTREVISION=	1
CATEGORIES=	net-im java
MASTER_SITES=	http://www.igniterealtime.org/downloadServlet?filename=wildfire/
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/./_/g}

MAINTAINER=	qpadla@gmail.com
COMMENT=	Openfire (formerly Wildfire) is an enterprise instant messaging server

RUN_DEPENDS=	classpath:${PORTSDIR}/java/javavmwrapper

DEPRECATED=	Use net-im/openfire instead of this port
EXPIRATION_DATE= 2007-12-12

USE_ANT=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

CONFLICTS=	openfire-[0-9]*

ALL_TARGET=	wildfire
USE_RC_SUBR=	wildfire
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}_src
BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${WRKSRC}/target/wildfire
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
VARLOG=		/var/log/wildfire
VARDB=		/var/db/wildfire
WETC=		${PREFIX}/etc/wildfire
PUSER=		wildfire
PGROUP=		${PUSER}

MLINKS=		${VARLOG} ${DATADIR}/logs \
	       	${VARDB} ${DATADIR}/embedded-db \
		${WETC} ${DATADIR}/conf

do-install:

	(cd ${INSTALL_WRKSRC}/lib && \
	${INSTALL_DATA} -m 744 *.jar ${JAVAJARDIR});

	${MKDIR} ${DATADIR};
	${MKDIR} ${VARLOG};
	${MKDIR} ${VARDB};

	(cd ${INSTALL_WRKSRC}/resources && ${FIND} . \
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
	${CP} -p ${INSTALL_WRKSRC}/conf/wildfire.xml ${EXAMPLESDIR}/wildfire.xml
	@if [ ! -f ${WETC}/wildfire.xml ]; then \
		${MKDIR} ${WETC}; \
		${CP} -p ${INSTALL_WRKSRC}/conf/wildfire.xml ${WETC}/wildfire.xml; \
	fi
	@PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${CHOWN} -R ${PUSER}:${PGROUP} ${WETC}
	${CHOWN} -R ${PUSER}:${PGROUP} ${VARDB}
	${CHOWN} -R ${PUSER}:${PGROUP} ${VARLOG}
	${CHOWN} -R ${PUSER}:${PGROUP} ${DATADIR}

	@${ECHO_CMD} "===> post-installation information for ${PKGNAME}:"
	@${ECHO_CMD} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD} ""

.include <bsd.port.mk>
