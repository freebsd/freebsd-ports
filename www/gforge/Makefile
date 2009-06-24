# New ports collection makefile for:   	gforge
# Date created:        			1 July 2003
# Whom:                			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	gforge
PORTVERSION=	4.5.19
CATEGORIES=	www devel
MASTER_SITES=	http://gforge.org/gf/download/frsrelease/150/245/

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Open Source collaborative software development tool

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

USE_BZIP2=		YES
USE_PERL5=		YES
HAS_CONFIGURE=		YES
USE_APACHE=		13
USE_AUTOTOOLS=	autoconf:262
NO_BUILD=		YES
USE_PHP=		pgsql session pcre
WANT_PHP_CLI=		YES
WANT_PHP_MOD=		YES

NO_PACKAGE=	The configure process uses hostname

.include <bsd.port.pre.mk>

.if ${PHP_VER} == 4
RUN_DEPENDS+=	${LOCALBASE}/share/jpgraph/imgdata_balls.inc:${PORTSDIR}/graphics/jpgraph
.else
RUN_DEPENDS+=	${LOCALBASE}/share/jpgraph/imgdata_balls.inc:${PORTSDIR}/graphics/jpgraph2
.endif

.if defined(WITH_JABBER)
CONFIGURE_ARGS+=	--enable-jabber
RUN_DEPENDS+=		${LOCALBASE}/sbin/jabberd:${PORTSDIR}/net-im/jabber
.endif

.if defined(WITH_MAILMAN)
RUN_DEPENDS+=		${LOCALBASE}/mailman:${PORTSDIR}/mail/mailman
.endif

WWW_ROOT?=	www
HOME_DIR?=	/home/gforge
BACKENDS?=	share/${PORTNAME}/backends
BACKEND_DIR=	${PREFIX}/${BACKENDS}
ETC_DIR?=	etc/gforge
PLIST_SUB+=	WWW_ROOT=${WWW_ROOT} BACKEND_DIR="${BACKENDS}" ETC_DIR=${ETC_DIR}

WWWROOT=	${PREFIX}/${WWW_ROOT}
ETCDIR=		${PREFIX}/${ETC_DIR}

.if !defined(WITH_DOMAINNAME)
HOSTNAME_CMD?=		/bin/hostname
SHORT_HOSTNAME!=	${HOSTNAME_CMD} -s
DOMAINNAME!=		${HOSTNAME_CMD} | ${SED} "s,${SHORT_HOSTNAME}\.,,"
.else
DOMAINNAME=		${WITH_DOMAINNAME}
.endif

CONFIGURE_WRKSRC=${WRKSRC}/contrib/autoconf
CONFIGURE_ARGS+=--enable-defaults=FreeBSD --with-domain-name=${DOMAINNAME} \
		--with-sys-path-to-jpgraph=${LOCALBASE}/share/jpgraph/
CONFIGURE_ENV+=	"WWWROOT=${WWWROOT}/gforge"

WWW_STUFF=	common www
BACKEND_STUFF=	backend cronjobs monitor utils plugins
SHARE_STUFF=	contrib db
ETC_STUFF=	gforge-httpd.conf.example local.inc.example \
		gforge-multi-host-httpd.conf.example

pre-everything::
.if defined(SYSTEM_NAME)
	CONFIGURE_ARGS+= --with-sys-name=${SYSTEM_NAME}
.else
	@${ECHO_MSG} "You can set your system name with SYSTEM_NAME=<your system name>"
.endif

post-patch:
	@${CHMOD} 744 ${WRKSRC}/contrib/autoconf/configure
	@${ECHO_MSG} "    ==> Patching CLI php scripts"
	@${FIND} ${WRKSRC} -name "*.php" | ${XARGS} ${REINPLACE_CMD} -e \
		"s,/usr/bin/php4,${LOCALBASE}/bin/php,"
	@${FIND} ${WRKSRC} -name "*.php" | ${XARGS} ${REINPLACE_CMD} -e \
		"s,/usr/bin/php,${LOCALBASE}/bin/php,"
	@${ECHO_MSG} "    ==> Patching patches"
	@${FIND} ${WRKSRC} -name "*.patch" | ${XARGS} ${REINPLACE_CMD} -e \
		"s,/usr/bin/php,${LOCALBASE}/bin/php,"
	@${ECHO_MSG} "    ==> Patching perl scripts"
	@${FIND} ${WRKSRC} -name "*.pl" | ${XARGS} ${REINPLACE_CMD} -e \
		"s,/usr/bin/perl,${PERL},"
.for f in utils/ldap/ldap-clean utils/ldap/ldap-del-user utils/ldap/ldap-dump utils/ldap/ldap-import utils/ldap/ldap-check-replica monitor/systemdaemon
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL}," ${WRKSRC}/${f}
.endfor
	@${ECHO_MSG} "    ==> Setting correct path"
	@${REINPLACE_CMD} -e "s,/usr/bin:/usr/games:/bin,${PATH}," ${WRKSRC}/monitor/systemdaemon
.for f in backend/include.pl utils/include.pl www/include/BaseLanguage.class www/include/pre.php www/include/squal_pre.php
	@${REINPLACE_CMD} -e "s,/etc/gforge,${ETCDIR},g" ${WRKSRC}/${f}
.endfor

post-configure:
	@${ECHO_MSG} "    ==> Preparing crontabs"
.for CRONFILE in README.root
	@${REINPLACE_CMD} -e "s,~/alexandria,${BACKEND_DIR},g" ${WRKSRC}/cronjobs/${CRONFILE}
.endfor
	@${ECHO_MSG} "    ==> Cleaning useless file"
	@${FIND} ${WRKSRC} -name "*.bak" -exec ${RM} {} \;
.for f in autom4te.cache configure.ac.orig configure.lineno config.log
	@${RM} -rfv ${WRKSRC}/contrib/autoconf/${f}
.endfor

do-install:
	@${MKDIR} ${ETCDIR}
	@${CP} ${WRKSRC}/contrib/autoconf/local.inc ${ETCDIR}/local.inc-dist
	@${CP} ${WRKSRC}/contrib/autoconf/sample-apache.vhost ${ETCDIR}/sample-apache.vhost-dist
.for f in ${ETC_STUFF}
	@${CP} -Rvf ${WRKSRC}/etc/${f} ${ETCDIR}
.endfor
.for dir in ${WWW_STUFF}
	@${MKDIR} ${WWWROOT}/gforge/${dir}
	@${CP} -Rvf ${WRKSRC}/${dir}/* ${WWWROOT}/gforge/${dir}
.endfor
.for dir in ${BACKEND_STUFF}
	@${MKDIR} ${BACKEND_DIR}/${dir}
	@${CP} -Rvf ${WRKSRC}/${dir}/* ${BACKEND_DIR}/${dir}
.endfor
.for dir in ${SHARE_STUFF}
	@${MKDIR} ${DATADIR}/${dir}
	@${CP} -Rvf ${WRKSRC}/${dir}/* ${DATADIR}/${dir}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${CP} -Rvf ${WRKSRC}/docs/* ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG} "--------------------------------------------------------"
	@${ECHO_MSG} "To start using gforge just copy ${ETCDIR}/local.inc-dist"
	@${ECHO_MSG} "to ${ETCDIR}/local.inc and edit it.
	@${ECHO_MSG} "A sample apache virtualhost can be found here:"
	@${ECHO_MSG} "${ETCDIR}/sample-apache.vhost-dist"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usefull files:"
	@${ECHO_MSG} "database template: ${DATADIR}/db/gforge.sql"
	@${ECHO_MSG} "crontab templates: ${BACKEND_DIR}/cronjobs/README.*"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you are having trouble displaying gantt charts,"
	@${ECHO_MSG} "please try increasing PHP's memory limit. Thanks to"
	@${ECHO_MSG} "Erik Greenwald for pointing this issue out."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "gforge is a huge project and complex to configure."
	@${ECHO_MSG} "If you have some great ideas for this port please"
	@${ECHO_MSG} "contact me directly (${MAINTAINER})."
	@${ECHO_MSG} "--------------------------------------------------------"

.include <bsd.port.post.mk>
