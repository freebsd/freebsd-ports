# New ports collection makefile for:    apache HTTPD w/FrontPage Module
# Version required:     1.3*	3.0.4 (3.0.2.1330)
# Date created:         Sat Oct 31 16:30:00 CDT 1997
# Whom:                 hetzels@westbend.net
#
# $FreeBSD$
#

DISTNAME=	apache_${AP_VERS}
PKGNAME=	apache_fp-${AP_VERS}
CATEGORIES=	www
MASTER_SITES=	http://www.apache.org/dist/ \
		ftp://ftp.microsoft.com/products/frontpage/ \
		http://www.freebsd.org/gifs/ \
		http://officeupdate.microsoft.com/frontpage/wpp/serk/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.microsoft.com/Products/frontpage/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/ftp.apache.org/apache/dist/ \
		ftp://ftp.rge.com/pub/infosystems/apache/dist/ \
		ftp://apache.compuex.com/pub/apache/dist/ \
		ftp://apache.arctic.org/pub/apache/dist/ \
		ftp://ftp.epix.net/pub/apache/dist/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.apache.org/apache/dist/ \
		ftp://ftp.connectnet.com/pub/www/apache/ \
		ftp://apache.technomancer.com/mirrors/apache/dist/ \
		ftp://ftp.raver.net/pub/ftp.apache.org/ \
		ftp://www3.service.digital.com/apache/dist/ \
		ftp://galileo.galilei.com/pub/apache/ \
		ftp://ftp.mtnranch.net/pub/apache/dist/ \
		ftp://ftp.iodynamics.com/pub/mirror/apache/dist/ \
		ftp://apache.nextpath.com/pub/apache/dist/
DISTFILES=	${APACHE} ${FRONTPAGE} powerlogo.gif fplogo.gif

MAINTAINER=	hetzels@westbend.net

#PATCH_SITES=	http://www.apache.org/dist/patches/apply_to_${AP_VERS}/
#PATCHFILES=

AP_VERS=	1.3.12
APACHE=		${DISTNAME}${EXTRACT_SUFX}
FRONTPAGE=	fp40.bsdi.tar.Z

EXTRACT_ONLY=	${APACHE}

BATCH?=		NO
CHMOD?=		/bin/chmod
FP_REV=		version4.0
FPINSTALL=	frontpage/${FP_REV}/fp_install.sh
CHANGESERVER=	frontpage/${FP_REV}/change_server.sh
FPSETPERM=	frontpage/${FP_REV}/set_default_perms.sh
README=		frontpage/${FP_REV}/readme.htm
SERK=		frontpage/${FP_REV}/serk
FPHTTPD=	${PREFIX}/frontpage/${FP_REV}/apache-fp
AP_SHARE=	${PREFIX}/share/doc/apache
MOD_FPDOCDIR=	${AP_SHARE}/manual/mod/mod_frontpage
MOD_FP=		${FILESDIR}/mod_frontpage.c
IMAGES_DIR=	${AP_SHARE}/manual/images

INSTALL_FILE=	${INSTALL} -c -m 555 -o bin -g bin

Y2K=		http://www.apache.org/foundation/Y2K.html
Y2K+=		http://computingcentral.msn.com/guide/year2000/msy2k/productinfo/frontpage.asp

PLIST=		${WRKDIR}/PLIST
PLIST_SUB=	FP_REV=${FP_REV}

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	 \
		  --prefix=${PREFIX} \
		  --server-gid=nogroup \
		  --with-perl=${PERL} \
		  --with-layout=${FILESDIR}/FreeBSD.layout:FreeBSD \
		  --without-confadjust \
		  --enable-shared=max \
		  --enable-module=most \
		  --enable-module=auth_db \
		  --disable-module=auth_dbm \
		  --add-module=${MOD_FP} \
		  --enable-shared=frontpage

# Currently perl version doesn't matter
USE_PERL5=	YES

OPTIM=		-DHARD_SERVER_LIMIT=512 \
		-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

#By default create an Optimized package.
.if ${BATCH} == YES
APACHE_PERF_TUNING= YES
.endif

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+= 	-DBUFFERED_LOGS -DFD_SETSIZE=1024
CFLAGS+=	-O6 -funroll-loops -fstrength-reduce -fomit-frame-pointer \
		-fexpensive-optimizations -ffast-math
.endif

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		OPTIM='${OPTIM}' \
		PATH="${PREFIX}/bin:${PATH}"

MAN1=	dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8

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
	   ${ECHO} "  Install the DES Library, then build apache-fp"; \
	   ${ECHO} ; \
	   ${ECHO} "  FreeBSD Handbook - Security (chapter 6)"; \
	   ${ECHO} "    http://www.freebsd.org/handbook/security.html#CRYPT"; \
	   ${ECHO} "  FAQ - I live outside the US. Can I use DES encryption?"; \
	   ${ECHO} "    http://www.freebsd.org/FAQ/install.html#AEN629"; \
	   ${ECHO} ; \
	   ${FALSE} ; \
	fi

post-extract:
	@${ECHO} "===>  Extracting FrontPage install scripts"
	cd ${WRKSRC} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${FRONTPAGE} \
		${EXTRACT_AFTER_ARGS} ${FPINSTALL} ${CHANGESERVER} \
		${README} ${FPSETPERM}

.if !defined(PATCH_DEBUG)
post-patch:
	@ cd ${WRKSRC} \
		&& find . -type f -name "*.orig" -print | xargs ${RM} -f
.endif

post-configure:
.if defined(SUEXEC)
	${CP} ${PKGDIR}/PLIST ${PLIST}
.else
	${CAT} ${PKGDIR}/PLIST | ${GREP} -v sbin/suexec > ${PLIST}
.endif

IMAGES=		apache_pb.gif fplogo.gif powerlogo.gif

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh file."; \
		${SED}	-e 's;PREFIX;${PREFIX};' \
			-e 's;PERL5;${PERL};' \
		< ${FILESDIR}/apache.sh.tmpl > ${PREFIX}/etc/rc.d/apache.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	@${INSTALL} -c -m 644 ${DISTDIR}/powerlogo.gif ${IMAGES_DIR}
	@${INSTALL} -c -m 644 ${DISTDIR}/fplogo.gif ${IMAGES_DIR}
	@${INSTALL} -c -m 644 ${AP_SHARE}/apache_pb.gif ${IMAGES_DIR}
	@( cd ${PREFIX}/share/doc/apache ; if [ -h images ] ; then ${RM} -f images ; fi ; ln -fs manual/images images)
	# Untar frontpage extentions
	@(cd ${PREFIX} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${FRONTPAGE} ${EXTRACT_AFTER_ARGS})
	@${RM} ${FPHTTPD}/httpd ${FPHTTPD}/httpd.Compat
	@${MKDIR} ${MOD_FPDOCDIR}
	@${CP} ${PREFIX}/${README} ${MOD_FPDOCDIR}/index.html
	@${LN} -fs ${PREFIX}/${SERK} ${MOD_FPDOCDIR}/serk
	@${INSTALL_FILE} ${WRKSRC}/${FPINSTALL} ${PREFIX}/${FPINSTALL}-dist
	@${INSTALL_FILE} ${WRKSRC}/${CHANGESERVER} ${PREFIX}/${CHANGESERVER}-dist
	@${INSTALL_FILE} ${WRKSRC}/${FPSETPERM} ${PREFIX}/${FPSETPERM}
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
