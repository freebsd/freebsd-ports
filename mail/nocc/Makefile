# New ports collection makefile for:	nocc
# Date created:		Fri Feb 3 13:31:37 CET 2002
# Whom:			Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	nocc
PORTVERSION=	0.9.5
CATEGORIES=	mail www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sysadmin@alexdupre.com

LIB_DEPENDS=	c-client4.8:${PORTSDIR}/mail/cclient
RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

NO_BUILD=	yes

do-install:
	${MKDIR} ${LOCALBASE}/www/nocc
	${CP} -Rp ${WRKSRC}/html ${WRKSRC}/lang ${WRKSRC}/themes \
	          ${LOCALBASE}/www/nocc
	${CP} -p ${WRKSRC}/*.php ${LOCALBASE}/www/nocc
	${CP} -p ${WRKSRC}/conf.php.dist ${LOCALBASE}/www/nocc/conf.php
	${CHOWN} -R www:www ${LOCALBASE}/www/nocc
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${DOCOWN} -g ${DOCGRP} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

post-install:
	@${ECHO} "****************************************************************"
	@${ECHO} "Nocc has been installed in ${LOCALBASE}/www/nocc directory."
	@${ECHO} "Change into this directory and make changes to the config"
	@${ECHO} "file (conf.php). The file is fairly well documented."
.if !defined(NOPORTDOCS)
	@${ECHO} "All documentation has been located in ${DOCSDIR}."
.endif
	@${ECHO} "****************************************************************"

.include <bsd.port.mk>
