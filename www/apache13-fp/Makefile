# New ports collection makefile for:    apache HTTPD w/FrontPage Module
# Date created:         Sat Oct 31 16:30:00 CDT 1997
# Whom:                 hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	apache
PKGNAMESUFFIX=	_fp
PORTVERSION=	1.3.23
CATEGORIES=	www
MASTER_SITES=	http://www.apache.org/dist/httpd/ \
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
DISTNAME=	${PORTNAME}_${PORTVERSION}
DISTFILES=	${APACHE} powerlogo.gif fplogo.gif

MAINTAINER=	hetzels@westbend.net

#PATCH_SITES=	http://www.apache.org/dist/patches/apply_to_${PORTVERSION}/
#PATCHFILES=

APACHE=		${DISTNAME}${EXTRACT_SUFX}

RUN_DEPENDS=	${LOCALBASE}/frontpage/version5.0/bin/owsadm.exe:${PORTSDIR}/www/frontpage

.ifndef WITHOUT_LIBEXPAT
LIB_DEPENDS+=	expat.2:${PORTSDIR}/textproc/expat2
.endif

.include <bsd.port.pre.mk>

ONLY_FOR_ARCHS=	i386 alpha

FP_VER=		5.0

EXTRACT_ONLY=	${APACHE}

BATCH?=		NO
CHMOD?=		/bin/chmod

MOD_FP=		${FILESDIR}/mod_frontpage.c
IMAGES_DIR=	${DOCSDIR}/manual/images

#
# Set APACHE_PERF_TUNING env. variable to YES to get maximum performance
#
HTTPD_USER?=	www
HTTPD_GROUP?=	www
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
		  --enable-module=most \
		  --enable-module=auth_db \
		  --enable-module=mmap_static \
		  --disable-module=auth_dbm \
		  --enable-shared=max \
		  --add-module=${MOD_FP} \
		  --enable-shared=frontpage

# Currently perl version doesn't matter
USE_PERL5=	YES

OPTIM=		-D_LARGEFILE_SOURCE \
		-D_FILE_OFFSET_BITS=64 \
		-DHARD_SERVER_LIMIT=512 \
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

.ifndef WITHOUT_LIBEXPAT
CONFIGURE_ENV+=	INCLUDES="${INCLUDES} -I ${LOCALBASE}/includes" \
		LDFLAGS="${LDFLAGS} -L ${LOCALBASE}/lib"
.endif

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
PLIST_SUB+=	SUEXEC=""
.else
PLIST_SUB+=	SUEXEC="@comment "
.endif

post-patch:
.if !defined(PATCH_DEBUG)
	@ cd ${WRKSRC} \
		&& find . -type f -name "*.orig" -print | xargs ${RM} -f
.endif

# Create apache user and group
pre-install:
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} PKG_USER=${HTTPD_USER} \
	    PKG_GROUP=${HTTPD_GROUP} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh file."; \
		${SED}	-e 's;PREFIX;${PREFIX};' \
			-e 's;PERL5;${PERL};' \
			-e 's;FP_VER;${FP_VER};' \
		< ${FILESDIR}/apache.sh.tmpl > ${PREFIX}/etc/rc.d/apache.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	@${INSTALL} -c -m 644 ${DISTDIR}/powerlogo.gif ${IMAGES_DIR}
	@${INSTALL} -c -m 644 ${DISTDIR}/fplogo.gif ${IMAGES_DIR}
	@${INSTALL} -c -m 644 ${DOCSDIR}/apache_pb.gif ${IMAGES_DIR}
	@( cd ${DOCSDIR} ; if [ -h images ] ; then ${RM} -f images ; fi ; ln -fs manual/images images)
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
