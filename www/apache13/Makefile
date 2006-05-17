# New ports collection makefile for:    apache HTTPD
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 ache@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=	1.3.36
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
DISTNAME=	apache_${PORTVERSION}

#PATCH_SITES=	${MASTER_SITE_APACHE_HTTPD}
#PATCH_SITE_SUBDIR=	patches/apply_to_1.3.36/
#PATCHFILES=
#PATCH_DIST_ARGS= -d ${WRKSRC}/src --forward --quiet -E ${PATCH_DIST_STRIP}

MAINTAINER=	ache@freebsd.org
COMMENT=	The extremely popular Apache http server. Very fast, very clean

CONFLICTS=	apache+mod_ssl-1.* apache+mod_ssl+ipv6-1.* apache+mod_ssl+modsnmp-1.* \
		apache+mod_ssl+mod_snmp+ipv6-1.* apache+mod_ssl+mod_accel-1.* \
		apache+mod_ssl+mod_snmp+mod_accel-1.* \
		apache+ipv6-1.* apache+ssl-1.* apache-2.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* thttpd-2.*
USE_PERL5=	yes
USE_RC_SUBR=	yes

.if defined(APACHE_DATADIR)
DATADIR=${APACHE_DATADIR}
.else
DATADIR=${PREFIX}/www
.endif
.if defined(APACHE_DOCUMENT_ROOT)
DOCUMENT_ROOT=${APACHE_DOCUMENT_ROOT}
.else
DOCUMENT_ROOT=${DATADIR}/data
.endif
.if defined(APACHE_CGIBIN_ROOT)
CGIBIN_ROOT=${APACHE_CGIBIN_ROOT}
.else
CGIBIN_ROOT=${DATADIR}/cgi-bin
.endif
DEFAULT_PATH=/bin:/usr/bin:${PREFIX}/bin
RC_SCRIPTS_SUB=PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

.if defined(WITHOUT_APACHE_EXPAT) && ${WITHOUT_APACHE_EXPAT} == yes
EXPAT_CONF+=	--disable-rule=EXPAT
.else
.if !defined(WITH_APACHE_INTERNAL_EXPAT) || ${WITH_APACHE_INTERNAL_EXPAT} != yes
LIB_DEPENDS+=	expat.6:${PORTSDIR}/textproc/expat2
.endif
EXPAT_CONF+=	--enable-rule=EXPAT
.endif

.if defined(WITH_APACHE_SUEXEC) && ${WITH_APACHE_SUEXEC} == yes

APACHE_SUEXEC_DOCROOT?=${DOCUMENT_ROOT}
APACHE_SUEXEC_LOG?=/var/log/httpd-suexec.log
APACHE_SUEXEC_USERDIR?=public_html
APACHE_SUEXEC_UIDMIN?=1000
APACHE_SUEXEC_GIDMIN?=1000
APACHE_SUEXEC_CALLER?=www

SUEXEC_CONF=	\
	--enable-suexec \
	--suexec-docroot=${APACHE_SUEXEC_DOCROOT} \
	--suexec-caller=${APACHE_SUEXEC_CALLER} \
	--suexec-uidmin=${APACHE_SUEXEC_UIDMIN} \
	--suexec-gidmin=${APACHE_SUEXEC_GIDMIN} \
	--suexec-logfile=${APACHE_SUEXEC_LOG} \
	--suexec-userdir=${APACHE_SUEXEC_USERDIR} \
	--suexec-safepath=${DEFAULT_PATH}

.if defined(APACHE_SUEXEC_UMASK)
SUEXEC_CONF+=	\
	--suexec-umask=${APACHE_SUEXEC_UMASK}
.endif

PLIST_SUB+=	SUB_SUEXEC=""
SUEXEC_MAN=	suexec.8

.else  # !SUEXEC

SUEXEC_CONF=
PLIST_SUB+=	SUB_SUEXEC="@comment "
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
		--datadir=${DATADIR} \
		--htdocsdir=${DOCUMENT_ROOT} \
		--cgidir=${CGIBIN_ROOT} \
		--without-confadjust \
		--enable-module=most \
		--enable-module=auth_db \
		--enable-module=mmap_static \
		--disable-module=auth_dbm \
		--enable-shared=max \
		${SUEXEC_CONF} \
		${EXPAT_CONF}

CFLAGS+=-DDOCUMENT_LOCATION=\\\\\"${DOCUMENT_ROOT}\\\\\" \
	-DDEFAULT_PATH=\\\\\"${DEFAULT_PATH}\\\\\"

#
# Set APACHE_HARD_SERVER_LIMIT env. variable to desired value
#
.if defined(APACHE_HARD_SERVER_LIMIT)
CFLAGS+=-DHARD_SERVER_LIMIT=${APACHE_HARD_SERVER_LIMIT}
.else
CFLAGS+=-DHARD_SERVER_LIMIT=512
.endif

#
# Set WITH_APACHE_PERF_TUNING env. variable to yes to get maximum performance
#
.if defined(WITH_APACHE_PERF_TUNING) && ${WITH_APACHE_PERF_TUNING} == yes
CFLAGS+=-DBUFFERED_LOGS
# Don't use OPTIM below, it is inserted _before_ CFLAGS
CFLAGS+=-O3
.endif

CONFIGURE_ENV=	OPTIM='${OPTIM}' LD_SHLIB='${CC}' LIBS='${LIBS}'

.if (!defined(WITHOUT_APACHE_EXPAT) || ${WITHOUT_APACHE_EXPAT} != yes) && \
    (!defined(WITH_APACHE_INTERNAL_EXPAT) || ${WITH_APACHE_INTERNAL_EXPAT} != yes)
CONFIGURE_ENV+=	\
		INCLUDES=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib
.endif

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 \
		${SUEXEC_MAN}

post-extract:
	@${SED}	${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/apache.sh > ${WRKSRC}/apache.sh

pre-install:
	-@${CHMOD} u+w ${DOCUMENT_ROOT}-dist ${CGIBIN_ROOT}-dist
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/apache.sh ${PREFIX}/etc/rc.d/apache.sh
	@${TOUCH} ${DOCUMENT_ROOT}-dist/EXAMPLE_DIRECTORY-DONT_ADD_OR_TOUCH_ANYTHING
	@${TOUCH} ${CGIBIN_ROOT}-dist/EXAMPLE_DIRECTORY-DONT_ADD_OR_TOUCH_ANYTHING
	@${CHMOD} a-w ${DOCUMENT_ROOT}-dist ${CGIBIN_ROOT}-dist
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
