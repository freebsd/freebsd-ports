# New ports collection makefile for:    apache HTTPD
# Version required:     1.2.1
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.35 1997/07/08 13:04:09 ache Exp $
#

DISTNAME=       apache_1.2.1
PKGNAME=        apache-1.2.1
CATEGORIES=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/

MAINTAINER=     ache@freebsd.org

# User-controlled variables list
# DIR_ACHE      - add SuppressHTMLPreamble option to directory index
#                 see http://www.nagual.ru/~ache/apache_dir.html
# SECURE_SERVER - build Apache with SSL

.if defined(DIR_ACHE)
PATCH_SITES+=   http://www.nagual.pp.ru/~ache/
PATCHFILES+=    dir.patch
VERS_ID=        dir/ache
.endif

.if defined(VERS_ID)
post-patch:
	@cd ${WRKSRC}/src && \
	mv Configuration Configuration.old && \
	sed 's;^#*OPTIM=.*;OPTIM= -DSERVER_SUBVERSION=\\"${VERS_ID}\\";' \
	< Configuration.old > Configuration
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		echo "[ -x /usr/local/sbin/httpd ] && /usr/local/sbin/httpd && echo -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
