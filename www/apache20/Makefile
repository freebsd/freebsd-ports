# New ports collection makefile for:	apache2
# Date created:				7 April 2001
# Whom:					Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=	2.0.48
CATEGORIES=	www ipv6
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		http://sheepkiller.nerim.net/ports/${PORTNAME}/:powerlogo
DISTNAME=	httpd-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz powerlogo.gif:powerlogo
DIST_SUBDIR=	apache2
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER?=	sheepkiller@cultdeadsheep.org
COMMENT?=	Version 2 of the extremely popular Apache http server

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

LATEST_LINK=	apache2

CONFLICTS=	apache+ipv6-1.* apache+modssl-1.* apache+ssl-1.* apache-1.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* thttpd-2.*

## Available knobs:
## By default, modules are compiled as dynamically loadable (DSO) modules.
##
##   Apache-related
##      WITH_MPM:                 prefork (default)
##                                worker
##                                perchild
##      HTTP_PORT:                default: 80
##      WITH_LDAP:                Enable LDAP support (mod_auth_ldap)
##      WITHOUT_PROXY:            Disable proxy support
##          WITH_CUSTOM_PROXY:    Let you choose which proxy modules you wish
##      WITHOUT_AUTH:             Disable auth modules
##          WITH_CUSTOM_AUTH:     Let you choose which auth modules you wish
##      WITHOUT_DAV:              Disable DAV support
##      IPV6_V6ONLY:              Disable IPv4 support
##      WITHOUT_SSL:              Disable SSL support
##      WITH_THREADS:             Enable threads support !! USE IT WITH CARE !!
##           WITH_CUSTOM_THREADS: Let you choose which threaded modules you want
##      WITH_EXPERIMENTAL:        Enable Experimental modules
##      WITH_DBM:                 Choose your DBM: bdb (Berkeley DB), gdbm or ndbm (default)
##          WITH_BERKELEYDB:      Choose your BerkeleyDB version: db2, db3 or db4 (default)
##      WITH_STATIC_SUPPORT:      Build statically linked support binaries
##      WITH_STATIC_APACHE:       Build a static version of httpd (implies WITH_STATIC_MODULES)
##      WITH_ALL_STATIC_APACHE:   All modules statically linked.
##      WITH_STATIC_MODULES:      List of modules to build modules statics (usefull for slave ports)
##                                (They must be already enabled (i.e. WITH_MODULES or with default configuration
##                                use 'make show-modules', to check if they are enabled)
##      WITH_EXPERIMENTAL:        Build and install experimental modules
##      WITH_EXTRA_MODULES:       To add addtionnal modules
##      WITH_MODULES:             List of your own modules
##      WITHOUT_MODULES:          Disable listed modules
##
##
##   Port-related:
##      NOPORTDOCS:               Do not install documentation
##      NO_CGI:                   Do not instal www/cgi-bin*
##      NO_ERROR:                   Do not instal www/error
##      NO_WWWDATA:               Do not instal www/data*
##      NO_ICONS:                 Do not instal www/icons*
##      NO_WWW:                   Implies NO_CGI, NO_WWWDATA, NO_ICONS and NO_ERROR
##
## Available make targets:
##      show-options:             prints this message
##      show-modules:             prints list of available modules
##
## Examples:
##      make WITHOUT_SSL=yes WITH_EXTRA_MODULES="bucketeer case_filter case_filter_in" WITHOUT_PROXY=yes
##      make WITH_STATIC_MODULES="ssl rewrite include" WITH_EXPERIMENTAL=yes WITH_CUSTOM_AUTH="auth auth_dbm"
##      make WITH_EXPERIMENTAL=yes WITHOUT_MODULES="access speling status"
##      make WITH_MODULES="include rewrite auth"
##

WITH_MPM?=	prefork # or worker, perchild
HTTP_PORT?=	80

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL5} \
		--with-port=${HTTP_PORT} \
		--with-expat=${LOCALBASE} \
		--libdir=${PREFIX_RELDEST}/lib/apache2 \
		--includedir=${PREFIX_RELDEST}/include/apache2

CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}" CONFIG_SHELL="${SH}"

DOCSDIR=	share/doc/apache2
PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
RC_SUB=		-e 's,@@PREFIX@@,${PREFIX_RELDEST},g'
MAKE_ENV+=	DESTDIR=${DESTDIR} EXPR_COMPAT=yes

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 suexec.8

.if !defined(IPV6_V6ONLY)
CONFIGURE_ARGS+=	--enable-v4-mapped
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.endif

.if defined(WITH_LDAP)
USE_LDAP=	YES
CONFIGURE_ARGS+=	--with-ldap \
			--with-ldap-lib="${LOCALBASE}/lib" \
			--with-ldap-include="${LOCALBASE}/include"
.endif

.if defined(NO_WWW)
NO_CGI=		YES
NO_WWWDATA=	YES
NO_ICONS=	YES
NO_ERROR=	YES
.endif

.if defined(NO_CGI)
MAKE_ENV+=	NO_CGI=yes
PLIST_SUB+=	CGI="@comment "
.else
PLIST_SUB+=	CGI=""
.endif

.if defined(NO_ICONS)
MAKE_ENV+=	NO_ICONS=yes
PLIST_SUB+=	ICONS="@comment "
.else
PLIST_SUB+=	ICONS=""
.endif

.if defined(NO_WWWDATA)
MAKE_ENV+=	NO_WWWDATA=yes
PLIST_SUB+=	WWWDATA="@comment "
.else
PLIST_SUB+=	WWWDATA=""
.endif

.if defined(NO_ERROR)
MAKE_ENV+=	NO_ERROR=yes
PLIST_SUB+=	ERROR="@comment "
.else
PLIST_SUB+=	ERROR=""
.endif

.if defined(WITH_STATIC_SUPPORT)
CONFIGURE_ARGS+=	--enable-static-support
.endif

.include <bsd.port.pre.mk>

.include "${.CURDIR}/Makefile.modules"

CONFIGURE_ARGS+=	--with-mpm=${WITH_MPM:L} ${CONFIGURE_TARGET}

show-options:
	@${EGREP} '^##' ${.CURDIR}/Makefile | ${SED} 's/##//'

show-modules:
	@for module in $(AVAILABLE_MODULES) ; do \
	${ECHO_MSG} -n "$${module}: ";\
	if ${ECHO_CMD} ${APACHE_MODULES} | ${GREP} -wq $${module} 2> /dev/null ; then \
			${ECHO_CMD} -n "enabled "; \
				if ${ECHO_CMD} ${WITH_STATIC_MODULES} | ${GREP} -wq $${module} 2> /dev/null ; then \
					${ECHO_CMD} "(static)" ; \
				else \
					${ECHO_CMD} "(shared)" ;\
				fi;\
			else\
			${ECHO_CMD} disabled ;\
		fi;\
	done

pre-everything::
	@${ECHO_MSG}	""
	@${ECHO_MSG}	"  To see all available knobs, type make show-options"
	@${ECHO_MSG}	""

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/powerlogo.gif ${WRKSRC}/docs/icons/freebsd.gif

post-patch:
	@cd ${WRKSRC}/docs/docroot && \
	 for f in index.html.*; do (\
	  ${REINPLACE_CMD} -e 's,apache_pb,icons/freebsd.gif"\
		ALT="[Powered by FreeBSD]"><IMG SRC="apache_pb2_ani,g' $$f \
	 ); done
	@${RM} -f ${WRKSRC}/docs/docroot/*.bak
	@${SED} ${RC_SUB} ${FILESDIR}/apache.sh >${WRKDIR}/apache2.sh
	@${SED} ${RC_SUB} ${FILESDIR}/config.layout >>${WRKSRC}/config.layout
	@${RM} -f ${WRKSRC}/docs/manual/index.html.ko.euc-kr

pre-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache2.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache2.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${WRKDIR}/apache2.sh ${PREFIX}/etc/rc.d/apache2.sh; \
	fi

.include <bsd.port.post.mk>
