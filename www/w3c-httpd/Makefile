# New ports collection makefile for:	w3c_httpd
# Version required:	3.0 / 2.17
# Date created:		29 October 1994
# Whom:			pst
#
# $Id: Makefile,v 1.10 1995/12/10 18:51:56 ache Exp $
#

DISTNAME=	WWW
PKGNAME=	w3c_httpd-3.0
CATEGORIES+=	www
MASTER_SITES=   ftp://ftp.w3.org/pub/httpd/ \
		ftp://ftp.w3.org/pub/libwww/
DISTFILES=      libwww_2.17_src.tar.Z \
		httpd_3.0_src.tar.gz

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
