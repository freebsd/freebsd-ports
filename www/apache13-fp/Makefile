# New ports collection makefile for:    apache HTTPD w/FrontPage
# Version required:     1.2.6	3.0.4 (3.0.2.1330)
# Date created:         Fri Oct 17 13:36:00 CDT 1997
# Whom:                 hetzels@westbend.net
#
# $Id$
#

DISTNAME=	apache_1.2.6
PKGNAME=	apache_fp-1.2.6
CATEGORIES=	www
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		ftp://ftp.microsoft.com/products/frontpage/\

MAINTAINER=	hetzels@westbend.net

APACHE=		${DISTNAME}${EXTRACT_SUFX}
FRONTPAGE=	fp30.bsdi3

DISTFILES=	${APACHE} ${FRONTPAGE}.tar.Z

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS= -d ${WRKSRC}/src -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS= -d ${WRKSRC}/src --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

EXTRACT_ONLY=	${APACHE}

IS_INTERACTIVE=	YES
NO_PACKAGE=	\
   "The FrontPage Installer needs to create FrontPage Admin user and password"

FPINSTALL=	frontpage/version3.0/fp_install.sh
CHANGESERVER=	frontpage/version3.0/change_server.sh
FPPATCH=	frontpage/version3.0/apache-fp/fp-patch-apache_1.2.5

INSTALL_FILE=${INSTALL} -c -m 555 -o bin -g bin

MAN1=		htpasswd.1
MAN8=		httpd.8
DOCDIR=		${PREFIX}/share/doc/apache

pre-fetch:
	@if [ ! -f /usr/lib/libdescrypt.a  -a ! -f /usr/lib/libdescrypt.so.* ] ; then \
	   ${ECHO} ; \
	   ${ECHO} "WARNING: MS Frontpage Extentions require the DES Library"; \
	   ${ECHO} "WARNING: Install the DES Library, then build apache-fp"; \
	   ${ECHO} ; \
	   ${FALSE} ; \
	fi

post-extract:
	@${ECHO} "===>  Extracting FrontPage patch, and install scripts"
	@cd ${WRKSRC} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${FRONTPAGE}.tar.Z ${FPINSTALL} ${FPPATCH} ${CHANGESERVER}

pre-patch:
	@${ECHO} "===>  Applying FrontPage patch"
	@cd ${WRKSRC} && ${PATCH} ${PATCH_DIST_ARGS} < ${WRKSRC}/${FPPATCH}

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${ECHO} "#!${SH}" > ${PREFIX}/etc/rc.d/apache.sh; \
		${ECHO} "[ -x ${PREFIX}/sbin/httpd ] && ${PREFIX}/sbin/httpd && ${ECHO} -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
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
	@cd ${WRKSRC}/htdocs; ${EXTRACT_CMD} cf - . | (cd ${DOCDIR} ; \
		${EXTRACT_CMD} xf -)
.endif
	@${SH} ${WRKSRC}/${FPINSTALL}
	@${INSTALL_FILE} ${WRKSRC}/${FPINSTALL} ${PREFIX}/${FPINSTALL}
	@${INSTALL_FILE} ${WRKSRC}/${CHANGESERVER} ${PREFIX}/${CHANGESERVER}

.include <bsd.port.mk>
