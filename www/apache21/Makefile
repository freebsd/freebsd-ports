# New ports collection makefile for:    apache HTTPD
# Version required:     1.1.1
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.15 1996/07/12 06:41:05 pst Exp $
#

DISTNAME=       apache_1.1.1
PKGNAME=        apache-1.1.1
CATEGORIES+=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/

MAINTAINER=	ache@freebsd.org

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		echo "[ -x /usr/local/sbin/httpd ] && /usr/local/sbin/httpd && echo -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
