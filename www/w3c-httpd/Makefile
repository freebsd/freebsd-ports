# New ports collection makefile for:	w3c-httpd
# Version required:	3.0A
# Date created:		29 October 1994
# Whom:			pst
#
# $Id: Makefile,v 1.13 1996/11/29 20:02:33 torstenb Exp $
#

DISTNAME=	w3c-httpd-3.0A
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.w3.org/pub/httpd/

MAINTAINER=	m230761@ingenieria.ingsala.unal.edu.co 

NO_WRKSUBDIR=	yes

WWW_ROOT=	${PREFIX}/www

do-install:
	${MKDIR} ${WWW_ROOT}/data ${WWW_ROOT}/cgi-bin ${WWW_ROOT}/htbin
	${CP} -R ${WRKSRC}/server_root/icons $(WWW_ROOT)
	${CP} ${WRKSRC}/server_root/config/*.conf $(PREFIX)/etc
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/freebsd/httpd ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/freebsd/htadm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/freebsd/htimage ${WWW_ROOT}/htbin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/freebsd/cgiparse ${WWW_ROOT}/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/Daemon/freebsd/cgiutils ${WWW_ROOT}/cgi-bin

.include <bsd.port.mk>
