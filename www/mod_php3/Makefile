# New ports collection makefile for:    apache HTTPD
# Version required:     1.0.5
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.11 1996/05/20 07:37:06 asami Exp $
#

DISTNAME=       apache_1.0.5
PKGNAME=        apache-1.0.5
CATEGORIES+=	www
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		ftp://www.apache.org/apache/dist/contrib/modules/
DISTFILES=      ${DISTNAME}.tar.gz mod_env.c

MAINTAINER=	pst@freebsd.org

EXTRACT_ONLY=   ${DISTNAME}.tar.gz

post-extract:
	cp ${DISTDIR}/mod_env.c ${WRKSRC}/src

post-install:
	@echo "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."
	@echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh
	@echo "[ -x /usr/local/sbin/httpd ] && /usr/local/sbin/httpd && echo -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh
	@chmod 751 ${PREFIX}/etc/rc.d/apache.sh

.include <bsd.port.mk>
