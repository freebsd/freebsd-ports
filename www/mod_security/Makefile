# New ports collection makefile for:	mod_security
# Date created:				4 June 2003
# Whom:					Marcelo Araujo <araujo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_security
PORTVERSION=	2.5.11
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	SF/mod-security/modsecurity-apache/${PORTVERSION}
DISTNAME=	${PORTNAME:S/_//:S/2//}-apache_${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	An intrusion detection and prevention engine

MAKE_JOBS_SAFE=	yes

LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre \
		apr-1:${PORTSDIR}/devel/apr

USE_APACHE=	2.0+
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
AP_GENPLIST=	yes
AP_INC=	${LOCALBASE}/include/libxml2
AP_LIB=	${LOCALBASE}/lib
USE_GNOME=	libxml2
MODULENAME=	mod_security2
WRKSRCTOP=	${WRKDIR}/${DISTNAME}
WRKSRC=		${WRKSRCTOP}/apache2
SRC_FILE=	*.c
PORTDOCS=	*
DOCS=		CHANGES LICENSE README.TXT modsecurity.conf-minimal
DOCSDIR=	${PREFIX}/share/doc/${MODULENAME}
SUB_FILES+=	mod_security2.conf
SUB_LIST+=	APACHEETCDIR="${APACHEETCDIR}"
PLIST_FILES+=	${APACHEMODDIR}/mod_security2.so
OPTIONS=	LUA "Embedded Lua language support" off \
		MLOGC "Build ModSecurity Log Collector" off

.include <bsd.port.pre.mk>

.if !defined(SKIP_RULES)
SUB_FILES+=	pkg-message.rules
.if defined(WITH_MLOGC)
PLIST_FILES+=	bin/mlogc
.endif
PLIST_DIRS+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules
PLIST_DIRS+=	${APACHEETCDIR}/Includes/mod_security2/base_rules
PLIST_DIRS+=	${APACHEETCDIR}/Includes/mod_security2/util
PLIST_DIRS+=	${APACHEETCDIR}/Includes/mod_security2
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/CHANGELOG
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/LICENSE
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/README
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/util/modsec-clamscan.pl
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/util/runav.pl
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/util/httpd-guardian.pl
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_10_config.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_10_global_config.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_20_protocol_violations.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_21_protocol_anomalies.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_40_generic_attacks.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_42_comment_spam.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_42_tight_security.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_55_marketing.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_41_xss_attacks.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_41_sql_injection_attacks.data
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_45_trojans.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_41_phpids_filters.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_50_outbound.data
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_46_et_web_rules.data
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_46_et_sql_injection.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_47_common_exceptions.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_41_phpids_converter.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_20_protocol_violations.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_49_enforcement.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_21_protocol_anomalies.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_35_bad_robots.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_30_http_policy.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_46_et_web_rules.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_40_generic_attacks.data
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_50_outbound.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_46_et_sql_injection.data
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_23_request_limits.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_41_sql_injection_attacks.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_40_generic_attacks.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_48_local_exceptions.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/base_rules/modsecurity_crs_60_correlation.conf
.endif

.if defined(WITH_LUA)
USE_LUA=	5.1+
CONFIGURE_ARGS+=	--with-lua=${LOCALBASE}
LIB_DEPENDS+=	lua-5.1.1:${PORTSDIR}/lang/lua
.else
CONFIGURE_ARGS+=	--without-lua
.endif
.if defined(WITH_MLOGC)
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-curl=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-curl
.endif
REINPLACE_ARGS=	-i ""
AP_EXTRAS+=	-DWITH_LIBXML2

CONFIGURE_ARGS+=	--with-apxs=${APXS} --with-pcre=${LOCALBASE}

post-patch:
	@${REINPLACE_CMD} -e '\
		s|SecRuleEngine On|SecRuleEngine DetectionOnly|; \
		s|SecAuditLog.*logs/modsec_audit.log|SecAuditLog /var/log/httpd-modsec2_audit.log|; \
		s|SecDebugLog.*logs/modsec_debug.log|SecDebugLog /var/log/httpd-modsec2_debug.log|; \
		s|SecServerSignature "Apache/2.2.0 (Fedora)"|SecServerSignature "Apache/${APACHE_VERSION:C/[0-9]/\0./g}x (${OPSYS})"|; \
		' ${WRKSRCTOP}/rules/modsecurity_crs_10_config.conf
.if defined(WITH_LUA)
	${REINPLACE_CMD} -e 's|%%LUA_VER%%|${LUA_VER}|' ${WRKSRC}/configure
.endif
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/configure

post-build:
.if defined(WITH_MLOGC)
	# XXX there is "mlogc-static" target in the Makefile, too
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} mlogc
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRCTOP} && ${COPYTREE_SHARE} "doc rules" ${DOCSDIR}/)
.endif
.if defined(WITH_MLOGC)
	${INSTALL_PROGRAM} ${WRKSRC}/mlogc-src/mlogc ${PREFIX}/bin/
.endif
.if !defined(SKIP_RULES)
	@${INSTALL_DATA} ${WRKDIR}/mod_security2.conf ${PREFIX}/${APACHEETCDIR}/Includes/
	@cd ${WRKSRCTOP} && ${PAX} -rw -pe -s +rules+mod_security2+ rules ${PREFIX}/${APACHEETCDIR}/Includes
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
