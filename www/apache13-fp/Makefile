# New ports collection makefile for:    apache HTTPD w/FrontPage Module
# Version required:     1.3*	3.0.4 (3.0.2.1330)
# Date created:         Sat Oct 31 16:30:00 CDT 1997
# Whom:                 hetzels@westbend.net
#
# $Id$
#

DISTNAME=       apache_1.3.3
PKGNAME=        apache_fp-1.3.3
CATEGORIES=	www
MASTER_SITES=	ftp://www.apache.org/apache/dist/ \
		ftp://ftp.microsoft.com/products/frontpage/

PATCH_SITES=    ftp://www.apache.org/apache/dist/patches/apply_to_1.3.3/ \
		http://www.apache.org/dist/patches/apply_to_1.3.3/

PATCHFILES=	core_404_log_bug.txt proxy_segv.txt

# This file will not apply, fails on hunk 2 for main/http_protocol.c
#PATCHFILES+=	server_error_filename.txt

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=       -d ${WRKSRC}/src -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=       -d ${WRKSRC}/src --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

MAINTAINER=	hetzels@westbend.net

APACHE=		${DISTNAME}${EXTRACT_SUFX}
FRONTPAGE=	fp30.bsdi3.tar.Z

DISTFILES=	${APACHE} ${FRONTPAGE}

EXTRACT_ONLY=	${APACHE}

IS_INTERACTIVE=	YES
NO_PACKAGE=	\
   "The FrontPage Installer needs to create FrontPage Admin user and password"

FPINSTALL=	frontpage/version3.0/fp_install.sh
CHANGESERVER=	frontpage/version3.0/change_server.sh
MOD_FP=		${FILESDIR}/mod_frontpage.c

INSTALL_FILE=${INSTALL} -c -m 555 -o bin -g bin

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= \
		 --sysconfdir=${PREFIX}/etc/apache \
		 --includedir=${PREFIX}/include/apache \
		 --logfiledir=/var/log \
		 --runtimedir=/var/run \
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
#                 --with-perl=${PERL5}

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
		 --suexec-userdir=${USER_DIR}
MAN8+=	suexec.8
.endif

pre-fetch:
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
	@${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh.tmpl file."
	@${CAT} ${FILESDIR}/apache.sh.tmpl | \
		${SED} -e 's;PREFIX;${PREFIX};' -e 's;PERL5;${PERL};' \
		> ${PREFIX}/etc/rc.d/apache.sh.tmpl
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${CP} ${PREFIX}/etc/rc.d/apache.sh.tmpl ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	else \
		${ECHO} "apache.sh exists, please compare with apache.sh.tmpl."; \
		${ECHO} "The template will regenerate the FrontPage suidkey"; \
		${ECHO} "file when the apache server is started/restarted."; \
	fi
	@${SH} ${WRKSRC}/${FPINSTALL}
	@${INSTALL_FILE} ${WRKSRC}/${FPINSTALL} ${PREFIX}/${FPINSTALL}
	@${INSTALL_FILE} ${WRKSRC}/${CHANGESERVER} ${PREFIX}/${CHANGESERVER}

.include <bsd.port.mk>
