# New ports collection makefile for:    apache HTTPD and HTTPSD
# Version required:     1.1.1
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 erich@rrnet.com
#
# $Id: Makefile,v 1.17 1996/08/11 14:49:21 markm Exp $
#

DISTNAME=       apache_1.1.1
PKGNAME=        apache-1.1.1
CATEGORIES+=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/

MAINTAINER=	ache@freebsd.org

.if defined(SECURE_SERVER)

PKGNAME=        apache_SSL-1.1.1
MAIN_SRC=	${DISTNAME}${EXTRACT_SUFX}
SSL_EXTRAS=	${DISTNAME}+1.3.ssl${EXTRACT_SUFX}
DISTFILES=	${MAIN_SRC} ${SSL_EXTRAS}
MASTER_SITES+=  ftp://ftp.ox.ac.uk/pub/crypto/SSL/
EXTRACT_ONLY=	${MAIN_SRC}
MD5_FILE=	${FILESDIR}/md5.SSL
PATCHDIR=	${.CURDIR}/patches.SSL
PKGDIR=		${.CURDIR}/pkg.SSL
CONFIGURE_SCRIPT=	configure.SSL
#DEPENDS=	${PORTSDIR}/security/SSLeay

post-extract:
	@cd ${WRKSRC} && tar xzf ${DISTDIR}/${SSL_EXTRAS}

pre-patch:
	@cd ${WRKSRC} && ${PATCH} ${PATCH_DIST_ARGS} < SSLpatch

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache_ssl.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache_ssl.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache_ssl.sh; \
		echo "[ -x /usr/local/sbin/httpsd ] && /usr/local/sbin/httpsd && echo -n ' httpsd'" >> ${PREFIX}/etc/rc.d/apache_ssl.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache_ssl.sh; \
	fi

.else

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		echo "[ -x /usr/local/sbin/httpd ] && /usr/local/sbin/httpd && echo -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.endif

.include <bsd.port.mk>
