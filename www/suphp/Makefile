# New ports collection makefile for:	suphp
# Date created:		15 September 2002
# Whom:			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	suphp
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.suphp.org/download/

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	suPHP is a combination which provides a wrapper for PHP

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${LOCALBASE}/bin/php:${PORTSDIR}/lang/php4

USE_REINPLACE=	yes
HAS_CONFIGURE=	no

MAKE_ARGS+=	APXS="${APXS}"
APXS?=		${LOCALBASE}/sbin/apxs
WWW_USER?=	www
WWW_GROUP?=	www
LOG_PATH?=	/var/log
PHP_PATH?=	${LOCALBASE}/bin/php

pre-configure:
	@${ECHO}
	@${ECHO} "*-------------------------------------------------------------*"
	@${ECHO} " suPHP conflicts with mod_php4. It works only with php command"
	@${ECHO} " line binairy."
	@${ECHO} " Options :"
	@${ECHO} "     - WWW_USER = Apache's User (default www)"
	@${ECHO} "     - Define CHECK_PATH, to enable suExec-like path checking"
	@${ECHO} "       (based on DocumentRoot directive)."
	@${ECHO} "     - LOG_PATH=/path/to/your/logs. Default /var/log/."
	@${ECHO} "     - PHP_PATH=/path/to/bin/php. Default ${LOCALBASE}/bin/php."
	@${ECHO} "*-------------------------------------------------------------*"
	@${ECHO}

do-configure:
	@${ECHO} "Setting User to : ${WWW_USER}"
	@${REINPLACE_CMD} -e 's!OPT_APACHE_USER "wwwrun"!OPT_APACHE_USER "${WWW_USER}"!' \
		${WRKSRC}/config.h
	@${ECHO} "Setting Group to : ${WWW_GROUP}"
	@${REINPLACE_CMD} -e 's!OPT_APACHE_GROUP "wwwrun"!OPT_APACHE_GROUP "${WWW_USER}"!' \
		${WRKSRC}/config.h
	@${ECHO} "Setting checkpath. (if enabled)"
.if !defined(CHECK_PATH)
	@${REINPLACE_CMD} -e 's!#define OPT_CHECKPATH!/*#define OPT_CHECKPATH*/!' \
		${WRKSRC}/config.h
.endif
	@${ECHO} "Setting logs path"
	@${REINPLACE_CMD} -e 's,OPT_LOGFILE "/opt/apache/var/logs/suphp_log",OPT_LOGFILE "${LOG_PATH}/suphp_log",' \
		${WRKSRC}/config.h
	 @${ECHO} "Setting php path"
	@${REINPLACE_CMD} -e 's,OPT_PATH_TO_PHP "/usr/bin/php",OPT_PATH_TO_PHP "${PHP_PATH}",' \
		${WRKSRC}/config.h
	@${ECHO} "Setting suphp path in mod_suphp"
	@${REINPLACE_CMD} -e "s,/usr/sbin/suphp,${PREFIX}/sbin/suphp," ${WRKSRC}/apache/mod_suphp.c

pre-install:
	${APXS} -i -a -c -n suphp ${WRKSRC}/apache/mod_suphp.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/apache ${DOCSDIR}/de-doc ${DOCSDIR}/de-doc/apache
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/apache/CONFIG ${DOCSDIR}/apache
	${INSTALL_DATA} ${WRKSRC}/apache/README ${DOCSDIR}/apache
	${INSTALL_DATA} ${WRKSRC}/apache/INSTALL ${DOCSDIR}/apache
	${INSTALL_DATA} ${WRKSRC}/apache/LICENSE ${DOCSDIR}/apache
	${INSTALL_DATA} -d ${WRKSRC}/de-doc/ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/de-doc/README.de ${DOCSDIR}/de-doc/
	${INSTALL_DATA} ${WRKSRC}/de-doc/INSTALL.de ${DOCSDIR}/de-doc/
	${INSTALL_DATA} ${WRKSRC}/de-doc/apache/README.de ${DOCSDIR}/de-doc/apache
	${INSTALL_DATA} ${WRKSRC}/de-doc/apache/INSTALL.de ${DOCSDIR}/de-doc/apache
	${INSTALL_DATA} ${WRKSRC}/de-doc/apache/CONFIG.de ${DOCSDIR}/de-doc/apache
.endif
	@${RM} mod_suphp.o
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
