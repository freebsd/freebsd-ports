# New ports collection makefile for:    apache HTTPSD
# Version required:     1.2.5
# Date created:     	15th August 1997
# Whom:			Mark Murray <mark@grondar.za>
#
# $Id: Makefile,v 1.46 1998/12/01 11:14:55 obrien Exp $

DISTNAME=       apache_1.2.6
PKGNAME=        apacheSSL-1.2.6
CATEGORIES=	www security
MASTER_SITES=   ftp://www.apache.org/apache/dist/ \
		ftp://ftp.ox.ac.uk/pub/crypto/SSL/Apache-SSL/
DISTFILES=      ${DISTNAME}${EXTRACT_SUFX} apache_1.2.6+ssl_1.15.tar.gz

MAINTAINER=     markm@freebsd.org

BUILD_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay
RUN_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay

BROKEN=		repository copy

EXTRACT_ONLY=   ${DISTNAME}${EXTRACT_SUFX}

RESTRICTED=     "Contains cryptography"

post-extract:
	@cd ${WRKSRC} && tar xzf ${DISTDIR}/apache_1.2.6+ssl_1.15.tar.gz

pre-patch:
	@cd ${WRKSRC} && ${PATCH} ${PATCH_DIST_ARGS} < SSLpatch

MAN1=		htpasswd.1
MAN8=		httpd.8
DOCDIR=		${PREFIX}/share/doc/apache

# Set it for local-supplied patch, f.e.
# VERS_ID = mods-1.0/me

.if defined(VERS_ID)
post-patch:
	@cd ${WRKSRC}/src && \
	${MV} Configuration Configuration.old && \
	${SED} 's;^#*OPTIM=.*;OPTIM= -DSERVER_SUBVERSION=\\"${VERS_ID}\\";' \
	< Configuration.old > Configuration
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apacheSSL.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apacheSSL.sh startup file."; \
		${ECHO} "#!/bin/sh" > ${PREFIX}/etc/rc.d/apacheSSL.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/httpsd ] && ${PREFIX}/sbin/httpsd && ${ECHO} -n ' httpsd'" >> ${PREFIX}/etc/rc.d/apacheSSL.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apacheSSL.sh; \
	fi
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/support/$i ${PREFIX}/man/man1
.endfor
.for i in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/support/$i ${PREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCDIR}
.for i in README LICENSE ABOUT_APACHE
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCDIR}
.endfor
	@cd ${WRKSRC}/htdocs; tar cf - . | (cd ${DOCDIR}; tar xf -)
.endif

.if !defined(USA_RESIDENT) || ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES if you are USA
	@${ECHO} resident or to NO if you aren\'t USA resident to build
	@${ECHO} this package.
	@false
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES
pre-build:
	cd ${WRKSRC} && ${PATCH} -p2 <${FILESDIR}/Makefile.rsa.patch
.endif
.endif

certificate:
	@if [ -f ${PREFIX}/etc/ssleay.cnf ]; then \
		cd ${WRKSRC}; ${MAKE} ${MAKE_ENV} $@; \
		${CP} ${WRKSRC}/SSLconf/conf/httpsd.pem ${PREFIX}/certs/cert.pem; \
	else \
		${ECHO} "You must create the file ${PREFIX}/etc/ssleay.cnf first."; \
	fi

.include <bsd.port.mk>
