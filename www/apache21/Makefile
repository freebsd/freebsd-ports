# New ports collection makefile for:    apache HTTPD
# Version required:     1.3a1
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 ache@nagual.pp.ru
#
# $Id: Makefile,v 1.37 1997/08/12 18:20:00 peter Exp $
#

DISTNAME=       apache_1.3a1
PKGNAME=        apache-1.3a1
CATEGORIES=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/

MAINTAINER=     ache@freebsd.org

# Set it for local-supplied patch, f.e.
# VERS_ID = mods-1.0/me

.if defined(VERS_ID)
post-patch:
	@cd ${WRKSRC}/src && \
	mv Configuration Configuration.old && \
	sed 's;^#*OPTIM=.*;OPTIM= -DSERVER_SUBVERSION=\\"${VERS_ID}\\";' \
	< Configuration.old > Configuration
.endif

post-patch:
	${CP} /usr/include/md5.h ${WRKSRC}/src/md5.h

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		echo "[ -x /usr/local/sbin/httpd ] && /usr/local/sbin/httpd && echo -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
