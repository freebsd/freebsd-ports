# New ports collection makefile for:    apache HTTPSD
# Version required:     1.1.1
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 markm@FreeBSD.org
#
# $Id: Makefile,v 1.35 1997/07/08 13:04:09 ache Exp $
#

DISTNAME=       apache_1.1.1
PKGNAME=        apache_SSL-1.1.1
CATEGORIES=	www
MASTER_SITES+=  ftp://www.apache.org/apache/dist/old/1.1/ \
		ftp://ftp.ox.ac.uk/pub/crypto/SSL/

MAIN_SRC=	${DISTNAME}${EXTRACT_SUFX}
SSL_EXTRAS=	${DISTNAME}+1.3.ssl${EXTRACT_SUFX}

DISTFILES=	${MAIN_SRC} ${SSL_EXTRAS}
EXTRACT_ONLY=	${MAIN_SRC}

MAINTAINER=	markm@freebsd.org

BROKEN=		"SSLeay has changed, and the patches for apache need more work"

DEPENDS=	${PORTSDIR}/security/SSLeay

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

.include <bsd.port.mk>
