# New ports collection makefile for:    apache HTTPSD
# Version required:     1.2.1
# Date created:     	15th August 1997
# Whom:			Richard Seaman <dick@tar.com>
#
# $Id: Makefile,v 1.38 1997/08/16 04:45:27 peter Exp $

DISTNAME=       apache_1.2.1
PKGNAME=        apacheSSL-1.2.1
CATEGORIES=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/ \
		ftp://ftp.ox.ac.uk/pub/crypto/SSL/

MAIN_SRC=	${DISTNAME}${EXTRACT_SUFX}
SSL_EXTRAS=	apache_1.2.0+ssl_1.8.tar.gz
DISTFILES=	${MAIN_SRC} ${SSL_EXTRAS}
EXTRACT_ONLY=	${MAIN_SRC}
BUILD_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay
RESTRICTED=     "Contains cryptography"

MAINTAINER=	markm@freebsd.org

post-extract:
	@cd ${WRKSRC} && tar xzf ${DISTDIR}/${SSL_EXTRAS}

# SSLpatch from SSL_EXTRAS is for apache_1.2.0 ... if/when it is upgraded
# we can revert to the commented out line.  There are only minor tweaks needed
# to get to SSLpatch-1.2.1 
pre-patch:
#       @cd ${WRKSRC} && ${PATCH} ${PATCH_DIST_ARGS} < SSLpatch
	@cd ${WRKSRC} && ${PATCH} ${PATCH_DIST_ARGS} \
		< ${FILESDIR}/SSLpatch-1.2.1

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache_ssl.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache_ssl.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache_ssl.sh; \
		echo "[ -x /usr/local/sbin/httpsd ] && /usr/local/sbin/httpsd && echo -n ' httpsd'" >> ${PREFIX}/etc/rc.d/apache_ssl.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache_ssl.sh; \
	fi
	@echo "Please note: in order to install a certificate you have to type:"
	@echo "    make certificate"

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@echo
	@echo You must set variable USA_RESIDENT to YES, if you are USA resident
	@echo or to NO, if you aren\'t USA resident to build this package.
	@echo You must also have installed RSAREF if you are USA resident.
	@false
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES
pre-build:
	${PATCH} <${FILESDIR}/Makefile.rsa.patch
.endif
.endif

certificate:
	cd ${WRKSRC}; ${MAKE} ${MAKE_ENV} $@
	cp ${WRKSRC}/SSLconf/conf/httpsd.pem ${PREFIX}/certs/cert.pem

.include <bsd.port.mk>
