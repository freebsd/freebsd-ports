# New ports collection makefile for:	apache2
# Date created:				7 April 2001
# Whom:					Hye-Shik Chang <perky@fallin.lv>
#
# $FreeBSD$
#
# For more information, please read Makefile.doc
#

PORTNAME=	apache
PORTVERSION=	2.0.48
PORTREVISION=	3
CATEGORIES=	www ipv6
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD} \
		http://sheepkiller.nerim.net/ports/${PORTNAME}/:powerlogo
DISTNAME=	httpd-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz powerlogo.gif:powerlogo
DIST_SUBDIR=	apache2
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER?=	clement@FreeBSD.org
COMMENT?=	Version 2 of the extremely popular Apache http server

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

LATEST_LINK=	apache2

CONFLICTS=	apache+ipv6-1.* apache+modssl-1.* apache+ssl-1.* apache-1.* apache_fp-1.* \
		caudium-devel-1.* caudium10-1.* caudium12-* \
		ru-apache+mod_ssl-1.* ru-apache-1.* thttpd-2.*

# patch files
PATCH_SITES+=		${MASTER_SITE_LOCAL:S/$/:clement/}
PATCH_SITE_SUBDIR=	clement/:clement
PATCHFILES+=		httpd-2.0.48-buildconf.patch:clement \
			httpd-2.0.48-ldap-fix.patch:clement
PATCH_DIST_STRIP+=	-p1:apache-clem
SCRIPTS_ENV+=		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
			LIBTOOL_VERSION=${LIBTOOL_VERSION}

WANT_AUTOCONF_VER?=	253
USE_LIBTOOL=	yes
USE_PERL5=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX_RELDEST} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL5} \
		--with-port=${WITH_HTTP_PORT} \
		--with-expat=${LOCALBASE} \
		--libdir=${PREFIX_RELDEST}/lib/apache2 \
		--includedir=${PREFIX_RELDEST}/include/apache2

CONFIGURE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" \
		CFLAGS="${CFLAGS}" \
 		LDFLAGS="${LDFLAGS}" CONFIG_SHELL="${SH}" \
		LOCALBASE="${LOCALBASE}"

PREFIX_RELDEST=	${PREFIX:S,^${DESTDIR},,}
RC_SUB=		-e 's,@@PREFIX@@,${PREFIX_RELDEST},g'
MAKE_ENV+=	DESTDIR=${DESTDIR} EXPR_COMPAT=yes

WITH_MPM?=	prefork # or worker, perchild

WITH_HTTP_PORT?=	80

.if !defined(WITH_IPV6_V6ONLY)
CONFIGURE_ARGS+=	--enable-v4-mapped
.endif

.if !defined(WITHOUT_SSL)
USE_OPENSSL=	yes
.endif

.if defined(WITH_STATIC_SUPPORT)
CONFIGURE_ARGS+=	--enable-static-support
.endif

.if defined(WITH_SSL_EXPERIMENTAL_ENGINE)
CFLAGS+=	-DSSL_EXPERIMENTAL_ENGINE
.endif

# for slave ports
.if !defined(MASTERDIR)
APACHEDIR=	${.CURDIR}
.else
APACHEDIR=	${MASTERDIR}
.endif

.if defined (WITH_LDAP)
USE_OPENLDAP=		YES
CONFIGURE_ARGS+=	--with-ldap \
			--with-ldap-lib="${LOCALBASE}/lib" \
			--with-ldap-include="${LOCALBASE}/include"
.endif

.include <bsd.port.pre.mk>

# Untested and may fail !
.if defined(WITH_APR_FROM_PORTS)
.    if defined (WITH_BDB) || defined(WITH_BERKELEYDB)
BROKEN=			"You can't set WITH_BDB or WITH_BERKELEYDB when WITH_APR_FROM_PORTS is defined"
.endif
LIB_DEPENDS+=		apr-0.9:${PORTSDIR}/devel/apr
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}/bin/apr-config \
			--with-apr-util=${LOCALBASE}/bin/apu-config
.else
.   if exists(${LOCALBASE}/lib/libapr-0.so)
BROKEN=				"apr is installed and may conflict with apache one\
					(if you want to use apr port define WITH_APR_FROM_PORTS,\
					at your own risk)"
.   endif
.endif

WITH_PTHREAD_LIBS?=	${PTHREAD_LIBS:S/-l//}

.include "${APACHEDIR}/Makefile.doc"
.include "${APACHEDIR}/Makefile.modules"

CONFIGURE_ARGS+=	--with-mpm=${WITH_MPM:L} ${CONFIGURE_TARGET}

show-options:
	@${SED} -ne 's/^##//p' ${APACHEDIR}/Makefile.doc

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
	@${ECHO_MSG}    "  You can check your modules configuration by using show-modules"
	@${ECHO_MSG}	""

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/powerlogo.gif ${WRKSRC}/docs/icons/freebsd.gif

pre-configure:
	@cd ${WRKSRC}; ${SETENV} ${SCRIPTS_ENV} ./buildconf

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
