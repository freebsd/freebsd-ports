# New ports collection makefile for:    apache HTTPD
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 ache@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=    1.3.27
PORTREVISION=   1
CATEGORIES=	www
MASTER_SITES=   http://www.apache.org/dist/httpd/ \
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
		ftp://apache.nextpath.com/pub/apache/dist/httpd/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/apache/dist/httpd,}
DISTNAME=	apache_${PORTVERSION}

#PATCH_SITES=    http://www.apache.org/dist/httpd/patches/apply_to_1.3.26/
#PATCHFILES=
#PATCH_DIST_ARGS= -d ${WRKSRC}/src --forward --quiet -E ${PATCH_DIST_STRIP}

MAINTAINER=	ache@freebsd.org

USE_PERL5=	yes

DATADIR=${PREFIX}/www
DOCUMENT_ROOT=${DATADIR}/data
DEFAULT_PATH=/bin:/usr/bin:${PREFIX}/bin

.if defined(WITH_APACHE_SUEXEC) && ${WITH_APACHE_SUEXEC} == yes

APACHE_SUEXEC_DOCROOT?=${DOCUMENT_ROOT}
APACHE_SUEXEC_LOG?=/var/log/httpd-suexec.log
APACHE_SUEXEC_USERDIR?=public_html

SUEXEC_CONF= \
	--enable-suexec \
	--suexec-docroot=${APACHE_SUEXEC_DOCROOT} \
	--suexec-caller=www \
	--suexec-uidmin=1000 \
	--suexec-gidmin=1000 \
	--suexec-logfile=${APACHE_SUEXEC_LOG} \
	--suexec-userdir=${APACHE_SUEXEC_USERDIR} \
	--suexec-safepath=${DEFAULT_PATH}

.if defined(APACHE_SUEXEC_UMASK)
SUEXEC_CONF+= \
	--suexec-umask=${APACHE_SUEXEC_UMASK}
.endif

PLIST_SUB+=     SUB_SUEXEC=""
SUEXEC_MAN=     suexec.8

.else   # !SUEXEC

SUEXEC_CONF=
PLIST_SUB+=     SUB_SUEXEC="@comment "
SUEXEC_MAN=

.endif  # !SUEXEC

HAS_CONFIGURE=	yes
# += for child ports
CONFIGURE_ARGS+=	\
		--prefix=${PREFIX} \
		--server-uid=www \
		--server-gid=www \
		--with-perl=${PERL} \
		--with-layout=FreeBSD \
		--without-confadjust \
		--enable-module=most \
		--enable-module=auth_db \
		--enable-module=mmap_static \
		--disable-module=auth_dbm \
		--enable-shared=max \
		${SUEXEC_CONF}

OPTIM=          -DDOCUMENT_LOCATION=\\"${DOCUMENT_ROOT}\\" \
		-DDEFAULT_PATH=\\"${DEFAULT_PATH}\\"

#
# Set APACHE_HARD_SERVER_LIMIT env. variable to desired value
#
.if defined(APACHE_HARD_SERVER_LIMIT)
OPTIM+=         -DHARD_SERVER_LIMIT=${APACHE_HARD_SERVER_LIMIT}
.else
OPTIM+=         -DHARD_SERVER_LIMIT=512
.endif

#
# Set WITH_APACHE_PERF_TUNING env. variable to YES to get maximum performance
#
.if defined(WITH_APACHE_PERF_TUNING) && ${WITH_APACHE_PERF_TUNING} == YES
OPTIM+=		-DBUFFERED_LOGS
CFLAGS+=	-O6 -fomit-frame-pointer
.endif

CONFIGURE_ENV=	OPTIM='${OPTIM}' LD_SHLIB='${CC}'

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=           ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 \
		${SUEXEC_MAN}

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/apache.sh \
		> ${WRKSRC}/apache.sh

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA} ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh-dist
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
