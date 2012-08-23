# New ports collection makefile for:	apache22
# Date created:				Dec 11 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#
# For more information, please read Makefile.doc
#

PORTNAME=	apache
PORTVERSION=	2.2.22
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
DISTNAME=	httpd-${PORTVERSION}
DIST_SUBDIR=	apache22

MAINTAINER?=	apache@FreeBSD.org
COMMENT?=	Version 2.2.x of Apache web server with ${WITH_MPM:L} MPM.

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
		apr-1:${PORTSDIR}/devel/apr1 \
		pcre:${PORTSDIR}/devel/pcre

MAKE_JOBS_SAFE=	yes

# to be removed if port is renamed to apache22
ETCDIR=		${PREFIX}/etc/${PORTNAME}22
WWWDIR=		${PREFIX}/www/${PORTNAME}22
LATEST_LINK?=	apache22

CONFLICTS=	caudium14-1.* \
		apache-2.0.* apache-*-2.0.* \
		apache-*-2.2.*

USE_APACHE=	common22
USE_BZIP2=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	autoconf libtool
USE_PERL5=	yes
USE_RC_SUBR=	apache22 htcacheclean
LIBTOOLFILES=	configure.in

USERS=		www
GROUPS=		www

# for slave ports
.if !defined(MASTERDIR)
APACHEDIR=	${.CURDIR}
.else
APACHEDIR=	${MASTERDIR}
.endif

WITH_MPM?=		prefork # or worker, event, itk
WITH_HTTP_PORT?=	80

MPM_ITK_VERSION?=	20110321-01

.include "${APACHEDIR}/Makefile.options"
.include <bsd.port.options.mk>

APU_CONFIG?=	${LOCALBASE}/bin/apu-1-config

CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL5} \
		--with-port=${WITH_HTTP_PORT} \
		--with-expat=${LOCALBASE} \
		--with-iconv=${LOCALBASE} \
		--enable-http \
		--with-pcre=${LOCALBASE} \
		--with-apr=${LOCALBASE}/bin/apr-1-config \
		--with-apr-util=${APU_CONFIG}

CONFIGURE_ENV=	\
		CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}

MAKE_ENV+=	EXPR_COMPAT=yes \
		INSTALL_MAN="${INSTALL_MAN}"

# =============================================
# CONFIGURE_ARGS willl be handled in Makefile.modules,
# here we do only OPTIONS fixups

.if defined(WITH_SUEXEC_RSRCLIMIT)
EXTRA_PATCHES+= ${FILESDIR}/extra-patch-suexec_rsrclimit
.if !defined(WITH_SUEXEC)
IGNORE=		suEXEC resource limit patch requires mod_suexec.\
		Please (re)run 'make config' and choose SUEXEC option also
.endif
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
WITH_MODULES+=	SSL
.endif

.if defined(WITH_AUTHNZ_LDAP)
WITH_LDAP=	yes
.endif

.if defined (WITH_LDAP)
USE_OPENLDAP=	yes
WITH_AUTHNZ_LDAP=yes
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
WITH_THREADS=	yes
.endif

.if defined(WITH_PGSQL)
USE_PGSQL=	yes
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
.endif

.include "${APACHEDIR}/Makefile.doc"
.include <bsd.port.pre.mk>
.include "${APACHEDIR}/Makefile.modules"

pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"  You can check your modules configuration by using make show-modules"
	@${ECHO_MSG}	"  To see all available knobs, type make show-options"
	@${ECHO_MSG}	"  To see all modules in different categories, type make show-categories"
	@${ECHO_MSG}	""

show-options:
	@${SED} -ne 's/^##//p' ${APACHEDIR}/Makefile.doc

post-patch:
	@${RM} -f ${WRKSRC}/docs/docroot/*.bak
	@${REINPLACE_CMD} -e 's," PLATFORM ",FreeBSD,' ${WRKSRC}/server/core.c
	@${INSTALL_DATA} ${WRKSRC}/NOTICE ${WRKSRC}/docs/manual

post-configure:
	@FTPUSERS=`${EGREP} -v '^#' /etc/ftpusers| ${TR} -s "\n" " "` ;\
	${REINPLACE_CMD} -e "s,%%FTPUSERS%%,$${FTPUSERS}," ${WRKSRC}/docs/conf/extra/httpd-userdir.conf
	@${REINPLACE_CMD} -e "s,%%WWWOWN%%,${WWWOWN}," -e  "s,%%WWWGRP%%,${WWWGRP}," ${WRKSRC}/docs/conf/httpd.conf
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/support/envvars-std

post-install:
	@${MKDIR} ${PREFIX}/etc/apache22/envvars.d
	@${MKDIR} ${PREFIX}/etc/apache22/Includes
	@${INSTALL_DATA} ${FILESDIR}/no-accf.conf ${PREFIX}/etc/apache22/Includes

.if defined(WITH_LOG_FORENSIC)
	@${INSTALL_SCRIPT} ${WRKSRC}/support/check_forensic ${PREFIX}/sbin
.endif

.if !defined(NOPORTDOCS)
.for dir in style/lang style/xsl/util style/xsl
	@[ -d ${DOCSDIR}/${dir}/ ] && ${TOUCH} ${DOCSDIR}/${dir}/.keepme
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
