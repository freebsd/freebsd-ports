# New ports collection makefile for:    apache HTTPD w/FrontPage Module
# Date created:         Sat Oct 31 16:30:00 CDT 1997
# Whom:                 hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	apache_fp
PORTVERSION=	1.3.19
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.apache.org/dist/httpd/ \
		ftp://ftp.microsoft.com/products/frontpage/ \
		ftp://www.westbend.net/Mirrors/ftp.microsoft.com/Products/frontpage/ \
		http://www.freebsd.org/gifs/ \
		http://officeupdate.microsoft.com/frontpage/wpp/serk/ \
		ftp://ftp.ccs.neu.edu/net/mirrors/ftp.apache.org/apache/dist/httpd/ \
		ftp://ftp.rge.com/pub/infosystems/apache/dist/httpd/ \
		ftp://apache.compuex.com/pub/apache/dist/httpd/ \
		ftp://apache.arctic.org/pub/apache/dist/httpd/ \
		ftp://ftp.epix.net/pub/apache/dist/httpd/ \
		ftp://ftp.ameth.org/pub/mirrors/ftp.apache.org/apache/dist/httpd/ \
		ftp://ftp.connectnet.com/pub/www/apache/httpd/ \
		ftp://apache.technomancer.com/mirrors/apache/dist/httpd/ \
		ftp://ftp.raver.net/pub/ftp.apache.org/httpd/ \
		ftp://www3.service.digital.com/apache/dist/httpd/ \
		ftp://galileo.galilei.com/pub/apache/httpd/ \
		ftp://ftp.mtnranch.net/pub/apache/dist/httpd/ \
		ftp://ftp.iodynamics.com/pub/mirror/apache/dist/httpd/ \
		ftp://apache.nextpath.com/pub/apache/dist/httpd/
DISTNAME=	apache_${PORTVERSION}
DISTFILES=	${APACHE} ${FRONTPAGE} powerlogo.gif fplogo.gif

MAINTAINER=	hetzels@westbend.net

#PATCH_SITES=	http://www.apache.org/dist/patches/apply_to_${PORTVERSION}/
#PATCHFILES=

APACHE=		${DISTNAME}${EXTRACT_SUFX}

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 alpha

.if ${ARCH} == i386
.ifdef WANT_FREEBSD_EXT
FRONTPAGE=	fp40.freebsd.tar.Z
.if ${OSVERSION} < 500016
PKGMESSAGE=	pkg-message.freebsd
.endif
.else
FRONTPAGE=	fp40.bsdi.tar.Z
EXTRA_PATCHES=	${FILESDIR}/change_server.bsdi ${FILESDIR}/fp_install.bsdi
.if ${OSVERSION} < 50016
PKGMESSAGE=	pkg-message.bsdi
.endif
.endif
.elif ${ARCH} == alpha
FRONTPAGE=	fp40.alpha.tar.Z
EXTRA_PATCHES=	${FILESDIR}/change_server.alpha ${FILESDIR}/fp_install.alpha
.endif

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

PLIST=		${WRKDIR}/PLIST
PLIST_SUB=	FP_REV=${FP_REV}

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#
HTTPD_USER?=	apache
HTTPD_GROUP?=	apache
USER_WEB_DIR?=	public_html

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	 \
		  --prefix=${PREFIX} \
		  --server-gid=nogroup \
		  --with-perl=${PERL} \
		  --with-layout=${FILESDIR}/FreeBSD.layout:FreeBSD \
		  --server-uid=${HTTPD_USER} \
		  --server-gid=${HTTPD_GROUP} \
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
APACHE_PERF_TUNING=	YES
.endif

.if defined(APACHE_PERF_TUNING) && ${APACHE_PERF_TUNING} == YES
OPTIM+=		-DBUFFERED_LOGS -DFD_SETSIZE=1024
CFLAGS+=	-O6 -funroll-loops -fstrength-reduce -fomit-frame-pointer \
		-fexpensive-optimizations -ffast-math
.endif

CONFIGURE_ENV=	CFLAGS='${CFLAGS}' \
		OPTIM='${OPTIM}' \
		PATH="${PREFIX}/bin:${PATH}"

MAN1=	dbmmanage.1 htdigest.1 htpasswd.1
MAN8=	ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8

.ifndef NO_SUEXEC
CONFIGURE_ARGS+=	--enable-suexec \
			--suexec-caller=${HTTPD_USER} \
			--suexec-docroot=${PREFIX}/www/data \
			--suexec-logfile=/var/log/httpd-suexec.log \
			--suexec-userdir=${USER_WEB_DIR} \
			--suexec-safepath='/bin:/usr/bin:${PREFIX}/bin'
MAN8+=	suexec.8
.endif

.if ${OSVERSION} < 500016
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
.if defined(WANT_FREEBSD_EXT) && ${ARCH} == i386
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "libc.so.3"; then \
	   ${ECHO} ; \
	   ${ECHO} "WARNING: MS FrontPage Extentions requires the COMPAT3X Libraries"; \
	   ${ECHO} "  Install the COMPAT3X Libraries, then build apache-fp"; \
	   ${ECHO} ; \
	   ${FALSE} ; \
	fi
.endif
.endif

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
.ifndef NO_SUEXEC
	${CP} ${PKGDIR}/pkg-plist ${PLIST}
.else
	${CAT} ${PKGDIR}/pkg-plist | ${GREP} -v sbin/suexec > ${PLIST}
.endif

IMAGES=		apache_pb.gif fplogo.gif powerlogo.gif

# Create apache user and group
pre-install:
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} PKG_USER=${HTTPD_USER} \
	    PKG_GROUP=${HTTPD_GROUP} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

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
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if ${OSVERSION} < 500016
.if ${ARCH} == i386
	@${CAT} ${PKGMESSAGE}
.endif
.endif

.include <bsd.port.post.mk>
