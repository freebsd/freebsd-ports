# New ports collection makefile for:    apache HTTPD w/FrontPage Module
# Version required:     1.3*	3.0.4 (3.0.2.1330)
# Date created:         Sat Oct 31 16:30:00 CDT 1997
# Whom:                 hetzels@westbend.net
#
# $Id: Makefile,v 1.6 1998/12/02 00:32:38 obrien Exp $
#

DISTNAME=       apache_${AP_VERS}
PKGNAME=        apache_fp-${AP_VERS}
CATEGORIES=	www
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		ftp://ftp.microsoft.com/products/frontpage/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.microsoft.com/Products/frontpage/
DISTFILES=	${APACHE} ${FRONTPAGE}

MAINTAINER=	hetzels@westbend.net

#PATCH_SITES=    ftp://www.apache.org/apache/dist/patches/apply_to_${AP_VERS}/ \
#		http://www.apache.org/dist/patches/apply_to_${AP_VERS}/
#PATCHFILES=

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=       -d ${WRKSRC}/src -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=       -d ${WRKSRC}/src --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

AP_VERS=	1.3.4
APACHE=		${DISTNAME}${EXTRACT_SUFX}
FRONTPAGE=	fp30.bsdi3.tar.Z

EXTRACT_ONLY=	${APACHE}

IS_INTERACTIVE=	YES
NO_PACKAGE=	\
   "The FrontPage Installer needs to create FrontPage Admin user and password"

FPINSTALL=	frontpage/version3.0/fp_install.sh
CHANGESERVER=	frontpage/version3.0/change_server.sh
MOD_FP=		${FILESDIR}/mod_frontpage.c

INSTALL_FILE=${INSTALL} -c -m 555 -o bin -g bin

Y2K=		http://www.apache.org/docs/misc/FAQ.html#year2000

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= \
		 --prefix=${PREFIX} \
		 --with-layout=GNU \
		 --sysconfdir=${PREFIX}/etc/apache \
		 --includedir=${PREFIX}/include/apache \
		 --localstatedir=/var \
		 --datadir=${PREFIX}/www \
		 --proxycachedir=${PREFIX}/www/proxy \
		 --libexecdir=${PREFIX}/libexec/apache \
		 --without-confadjust \
		 --enable-shared=remain \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --disable-module=auth_dbm \
		 --add-module=${MOD_FP} \
		 --enable-shared=frontpage

# Currently perl version doesn't matter
USE_PERL5=	 YES
CONFIGURE_ARGS+= --with-perl=${PERL5}

OPTIM=-DHARD_SERVER_LIMIT=512 \
-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+= -DBUFFERED_LOGS
CFLAGS+= -O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV= OPTIM='${OPTIM}'

MAN1=   ab.1 apachectl.1 dbmmanage.1 htdigest.1 htpasswd.1
MAN8=   apxs.8 httpd.8 logresolve.8 rotatelogs.8

.if defined(SUEXEC)
HTTPD_USER?=www
USER_DIR?=public_html
CONFIGURE_ARGS+= --enable-suexec \
		 --suexec-caller=${HTTPD_USER} \
		 --suexec-docroot=${PREFIX}/www/data \
		 --suexec-logfile=/var/log/httpd-suexec.log \
		 --suexec-userdir=${USER_DIR} \
		 --suexec-safepath='/bin:/usr/bin:${PREFIX}/bin'
MAN8+=	suexec.8
.endif

pre-extract:
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "-ldescrypt"; then \
	   ${ECHO} ; \
	   ${ECHO} "WARNING: MS FrontPage Extentions require the DES Library"; \
	   ${ECHO} "WARNING: Install the DES Library, then build apache-fp"; \
	   ${ECHO} ; \
	   ${FALSE} ; \
	fi

post-extract:
	@${ECHO} "===>  Extracting FrontPage install scripts"
	@cd ${WRKSRC} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${FRONTPAGE} ${FPINSTALL} ${CHANGESERVER}

post-install:
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh file."
	@${CAT} ${FILESDIR}/apache.sh.tmpl | \
		${SED} -e 's;PREFIX;${PREFIX};' -e 's;PERL5;${PERL};' \
		> ${PREFIX}/etc/rc.d/apache.sh
	@chmod 751 ${PREFIX}/etc/rc.d/apache.sh
	@${CAT} ${WRKSRC}/${FPINSTALL} | \
		${SED} -e 's;PREFIX;${PREFIX};' > ${WRKDIR}/tmp.fpinstall
	@${SH} ${WRKDIR}/tmp.fpinstall
	@${INSTALL_FILE} ${WRKDIR}/tmp.fpinstall ${PREFIX}/${FPINSTALL}
	@${CAT} ${WRKSRC}/${CHANGESERVER} | \
		${SED} -e 's;PREFIX;${PREFIX};' > ${WRKDIR}/tmp.changeserver
	@${INSTALL_FILE} ${WRKDIR}/tmp.changeserver ${PREFIX}/${CHANGESERVER}

.include <bsd.port.mk>
