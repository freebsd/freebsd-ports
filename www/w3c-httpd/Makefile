# New ports collection makefile for:	cern_httpd
# Version required:	3.0 / 2.17
# Date created:		29 October 1994
# Whom:			pst
#
# $Id: Makefile,v 1.7 1995/10/03 07:03:46 asami Exp $
#

DISTNAME=	WWW
PKGNAME=	cern_httpd-3.0
CATEGORIES+=	www
MASTER_SITES=	ftp://www0.cern.ch/pub/www/src/
DISTFILES=	WWWDaemon_3.0.tar.Z WWWLibrary_2.17.tar.Z

MAINTAINER=	sa2c@and.or.jp

WWW_ROOT=	${PREFIX}/www

do-install:
	-mkdir ${WWW_ROOT} \
	       ${WWW_ROOT}/data ${WWW_ROOT}/cgi-bin ${WWW_ROOT}/htbin
	cd ${WRKSRC}/server_root; pax -rw * ${WWW_ROOT}
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/Daemon/unix/httpd ${PREFIX}/libexec
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/Daemon/unix/htadm ${PREFIX}/bin
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/Daemon/unix/htimage ${WWW_ROOT}/htbin
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/Daemon/unix/cgiparse ${WWW_ROOT}/cgi-bin
	install -c -s -o ${BINOWN} -g ${BINGRP} -m ${BINMODE} \
		${WRKSRC}/Daemon/unix/cgiutils ${WWW_ROOT}/cgi-bin

.include <bsd.port.mk>
