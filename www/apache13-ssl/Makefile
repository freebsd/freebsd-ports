# New ports collection makefile for:    apache HTTPSD
# Version required:     1.2.4
# Date created:     	15th August 1997
# Whom:			Richard Seaman <dick@tar.com>
#
# $Id: Makefile,v 1.39 1997/08/16 16:01:10 andreas Exp $

DISTNAME=       apache_1.2.4
PKGNAME=        apacheSSL-1.2.4
CATEGORIES=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/ \
		ftp://ftp.ox.ac.uk/pub/crypto/SSL/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} apache_1.2.4+ssl_1.9.tar.gz

MAINTAINER=	markm@freebsd.org

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

BUILD_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay

RESTRICTED=     "Contains cryptography"

post-extract:
	@cd ${WRKSRC} && tar xzf ${DISTDIR}/apache_1.2.4+ssl_1.9.tar.gz

pre-patch:
	@cd ${WRKSRC} && ${PATCH} ${PATCH_DIST_ARGS} < SSLpatch

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache_ssl.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache_ssl.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache_ssl.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/httpsd ] && ${PREFIX}/sbin/httpsd && ${ECHO} -n ' httpsd'" >> ${PREFIX}/etc/rc.d/apache_ssl.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache_ssl.sh; \
	fi
	@${ECHO} "Please note: in order to install a certificate you have to"
	@${ECHO} "type:"
	@${ECHO} "    make certificate"

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES, if you are USA
	@${ECHO} resident or to NO, if you aren\'t USA resident to build
	@${ECHO} this package.
	@${ECHO} You must also have installed RSAREF if you are USA resident.
	@false
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES
pre-build:
	${PATCH} <${FILESDIR}/Makefile.rsa.patch
.endif
.endif

certificate:
	cd ${WRKSRC}; ${MAKE} ${MAKE_ENV} $@
	${CP} ${WRKSRC}/SSLconf/conf/httpsd.pem ${PREFIX}/certs/cert.pem

.include <bsd.port.mk>
