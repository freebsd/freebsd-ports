# New ports collection makefile for:    apache HTTPD w/FrontPage Module
# Date created:         Sat Oct 31 16:30:00 CDT 1997
# Whom:                 hetzels@westbend.net
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=	1.3.27
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		http://www.freebsd.org/gifs/:powerlogo \
		http://www.microsoft.com/frontpage/images/:fplogo
MASTER_SITE_SUBDIR=	old
PKGNAMESUFFIX=	_fp
DISTNAME=	${PORTNAME}_${PORTVERSION}
DISTFILES=	${APACHE} powerlogo.gif:powerlogo createdwFP.gif:fplogo

MAINTAINER=	apache@FreeBSD.org
COMMENT=	The Apache webserver with MS Frontpage Module

#BROKEN=		"Checksum mismatch"
FORBIDDEN=	multiple vulnerabilities: http://www.apacheweek.com/features/security-13
EXPIRATION_DATE=2004-08-20
DEPRECATED=	${FORBIDDEN}

#PATCH_SITES=	${MASTER_SITE_APACHE_HTTPD}
#PATCH_SITE_SUBDIR=	patches/apply_to_${PORTVERSION}/
#PATCHFILES=

CONFLICTS=	apache+mod_ssl-1.* apache+mod_ssl+ipv6-1.* apache+mod_ssl+modsnmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1. \
		apache+ipv6-1.* apache+ssl-1.* apache-1.* apache-2.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* thttpd-2.*
APACHE=		${DISTNAME}${EXTRACT_SUFX}

RUN_DEPENDS=	${LOCALBASE}/frontpage/version5.0/bin/owsadm.exe:${PORTSDIR}/www/frontpage

.ifndef WITHOUT_LIBEXPAT
LIB_DEPENDS+=	expat.5:${PORTSDIR}/textproc/expat2
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
		  --with-layout=FreeBSD \
		  --manualdir=${DOCSDIR}/manual \
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
		&& ${FIND} . -type f -name "*.orig" -print | ${XARGS} ${RM} -f
.endif

# Create apache user and group
pre-install:
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} PKG_USER=${HTTPD_USER} \
	    PKG_GROUP=${HTTPD_GROUP} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh file."; \
		${SED}	-e 's;%%PREFIX%%;${PREFIX};' \
			-e 's;%%PERL5%%;${PERL};' \
			-e 's;%%FP_VER%%;${FP_VER};' \
		< ${FILESDIR}/apache.sh.tmpl > ${PREFIX}/etc/rc.d/apache.sh; \
		${CHMOD} 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	@${INSTALL} -c -m 644 ${DISTDIR}/powerlogo.gif ${IMAGES_DIR}
	@${INSTALL} -c -m 644 ${DISTDIR}/createdwFP.gif ${IMAGES_DIR}
	@${INSTALL_DATA} ${FILESDIR}/createdwFP.txt ${DOCSDIR}
	@${INSTALL} -c -m 644 ${DOCSDIR}/apache_pb.gif ${IMAGES_DIR}
	@( cd ${DOCSDIR} ; if [ -h images ] ; then ${RM} -f images ; fi ; ln -fs manual/images images)
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
