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

.if defined(PATCH_DEBUG)
PATCH_DIST_ARGS=	-d ${WRKSRC}/src -E ${PATCH_DIST_STRIP}
.else
PATCH_DIST_ARGS=	-d ${WRKSRC}/src --forward --quiet -E ${PATCH_DIST_STRIP}
.endif

AP_VERS=	1.3.9
APACHE=		${DISTNAME}${EXTRACT_SUFX}
FRONTPAGE=	fp40.bsdi.tar.Z

EXTRACT_ONLY=	${APACHE}

IS_INTERACTIVE=	YES
NO_PACKAGE=	\
   "The FrontPage Installer needs to create FrontPage Admin user and password"

FPINSTALL=	frontpage/version4.0/fp_install.sh
CHANGESERVER=	frontpage/version4.0/change_server.sh
README=		frontpage/version4.0/readme.htm
SERK=		frontpage/version4.0/serk
MOD_FPDOCDIR=	share/doc/apache/manual/mod/mod_frontpage
MOD_FP=		${FILESDIR}/mod_frontpage.c
IMAGES_DIR=	share/doc/apache/manual/images
IMAGES_VTI=	${PREFIX}/www/data/images/_vti_cnf

INSTALL_FILE=${INSTALL} -c -m 555 -o bin -g bin

Y2K=		http://www.apache.org/foundation/Y2K.html
Y2K+=		http://computingcentral.msn.com/guide/year2000/msy2k/productinfo/frontpage.asp

PLIST=		${WRKDIR}/PLIST
PLIST_SUB=	FP_REV=version4.0

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	 --prefix=${PREFIX} \
		 --with-layout=GNU \
		 --with-perl=${PERL} \
		 --bindir=${PREFIX}/bin \
		 --sbindir=${PREFIX}/sbin \
		 --libexecdir=${PREFIX}/libexec/apache \
		 --mandir=${PREFIX}/man \
		 --sysconfdir=${PREFIX}/etc/apache \
		 --datadir=${PREFIX}/www \
		 --includedir=${PREFIX}/include/apache \
		 --localstatedir=/var \
		 --runtimedir=/var/run \
		 --logfiledir=/var/log \
		 --proxycachedir=/var/spool/proxy \
		 --without-confadjust \
		 --enable-module=most \
		 --enable-module=auth_db \
		 --disable-module=auth_dbm \
		 --add-module=${MOD_FP} \
		 --enable-shared=frontpage \
		 --enable-shared=max

# Currently perl version doesn't matter
USE_PERL5=	YES

OPTIM=		-DHARD_SERVER_LIMIT=512 \
		-DDOCUMENT_LOCATION=\\"${PREFIX}/www/data/\\" \
		-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

.if defined(APACHE_PERF_TUNING)
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
	   ${ECHO} "WARNING: Install the DES Library, then build apache-fp"; \
	   ${ECHO} ; \
	   ${FALSE} ; \
	fi

post-extract:
	@${ECHO} "===>  Extracting FrontPage install scripts"
	@cd ${WRKSRC} && \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${FRONTPAGE} \
		${EXTRACT_AFTER_ARGS} ${FPINSTALL} ${CHANGESERVER} \
		${README}

.if !defined(PATCH_DEBUG)
post-patch:
	@ cd ${WRKSRC} \
		&& find . -type f -name "*.orig" -print | xargs ${RM} -f
.endif

post-configure:
.if defined(SUEXEC)
	${CP} ${PKGDIR}/PLIST ${PLIST}
.else
	${CAT} ${PKGDIR}/PLIST | ${GREP} -v sbin/suexec >${PLIST}
.endif

IMAGES=		apache_pb.gif fplogo.gif powerlogo.gif

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh file."; \
		${CAT} ${FILESDIR}/apache.sh.tmpl | \
			${SED}	-e 's;PREFIX;${PREFIX};' \
				-e 's;PERL5;${PERL};' \
				> ${PREFIX}/etc/rc.d/apache.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	@${INSTALL} -c -m 644 ${DISTDIR}/powerlogo.gif ${PREFIX}/${IMAGES_DIR}
	@${INSTALL} -c -m 644 ${DISTDIR}/fplogo.gif ${PREFIX}/${IMAGES_DIR}
	@${INSTALL} -c -m 644 ${PREFIX}/share/doc/apache/apache_pb.gif ${PREFIX}/${IMAGES_DIR}
	@mkdir -p ${PREFIX}/www/data/images
	@( cd ${PREFIX}/share/doc/apache ; if [ -h images ] ; then ${RM} -f images ; fi ; ln -fs manual/images images)
.for file in ${IMAGES}
	@if [ ! -f ${PREFIX}/www/data/images/${file} ]; then \
		${CP} -rp ${PREFIX}/${IMAGES_DIR}/${file} ${PREFIX}/www/data/images ; \
	fi
.endfor
	@${CAT} ${WRKSRC}/${FPINSTALL} | \
		${SED}  -e 's;PREFIX;${PREFIX};' \
			-e 's;MOD_FPDOCDIR;${PREFIX}/${MOD_FPDOCDIR};' \
			> ${WRKDIR}/tmp.fpinstall
	@${SH} ${WRKDIR}/tmp.fpinstall
#Add the appropriate comment to the images/_vti_cnf file.
	@if [ -d ${IMAGES_VTI} ]; then \
		if [ ! "`grep description ${IMAGES_VTI}/apache_pb.gif`" ] ; then \
			${ECHO} "vti_description:SW|Apache Webserver" >> ${IMAGES_VTI}/apache_pb.gif ;\
		fi ; \
		if [ ! "`grep description ${IMAGES_VTI}/fplogo.gif`" ] ; then \
			${ECHO} "vti_description:SW|Created with Microsoft FrontPage 2000" >> ${IMAGES_VTI}/fplogo.gif ; \
		fi ; \
		if [ ! "`grep description ${IMAGES_VTI}/powerlogo.gif`" ] ; then \
			${ECHO} "vti_description:SW|Powered by FreeBSD" >> ${IMAGES_VTI}/powerlogo.gif ; \
		fi ; \
	fi
	@${INSTALL_FILE} ${WRKDIR}/tmp.fpinstall ${PREFIX}/${FPINSTALL}
	@${CAT} ${WRKSRC}/${CHANGESERVER} | \
		${SED} -e 's;PREFIX;${PREFIX};' > ${WRKDIR}/tmp.changeserver
	@${INSTALL_FILE} ${WRKDIR}/tmp.changeserver ${PREFIX}/${CHANGESERVER}
	@${MKDIR} ${PREFIX}/${MOD_FPDOCDIR}
	@${CP} ${PREFIX}/${README} ${PREFIX}/${MOD_FPDOCDIR}/index.html
	@${LN} -s ${PREFIX}/${SERK} ${PREFIX}/${MOD_FPDOCDIR}/serk

.include <bsd.port.mk>
