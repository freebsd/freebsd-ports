# New ports collection makefile for:	mod_security2
# Date created:				9 November 2006
# Whom:					Dominic Mitchell <dom@happygiraffe.net>
#
# $FreeBSD$
#

PORTNAME=	mod_security21
PORTVERSION=	2.1.7
CATEGORIES=	www security
MASTER_SITES=	http://www.modsecurity.org/download/
DISTNAME=	${PORTNAME:S/_//:S/21//}-apache_${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	An intrusion detection and prevention engine

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_EXTRAS+=	-DWITH_LIBXML2
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

.if !defined(SKIP_RULES)
SUB_FILES+=	pkg-message.rules

PLIST_DIRS+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules
PLIST_DIRS+=	${APACHEETCDIR}/Includes/mod_security2

PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/CHANGELOG
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/LICENSE
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/README
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_23_request_limits.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_10_config.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_20_protocol_violations.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_21_protocol_anomalies.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_30_http_policy.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_35_bad_robots.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_40_generic_attacks.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_45_trojans.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/modsecurity_crs_50_outbound.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_20_protocol_violations.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_21_protocol_anomalies.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_40_generic_attacks.conf
PLIST_FILES+=	${APACHEETCDIR}/Includes/mod_security2/optional_rules/modsecurity_crs_55_marketing.conf

.endif

REINPLACE_ARGS=	-i ""

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} == 22
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
.endif

post-patch:
	@${REINPLACE_CMD} -e '\
		s|SecRuleEngine On|SecRuleEngine DetectionOnly|; \
		s|SecAuditLog.*logs/modsec_audit.log|SecAuditLog /var/log/httpd-modsec2_audit.log|; \
		s|SecDebugLog.*logs/modsec_debug.log|SecDebugLog /var/log/httpd-modsec2_debug.log|; \
		s|SecServerSignature "Apache/2.2.0 (Fedora)"|SecServerSignature "Apache/${APACHE_VERSION:C/[0-9]/\0./g}x (${OPSYS})"|; \
		' ${WRKSRCTOP}/rules/modsecurity_crs_10_config.conf

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRCTOP}/,} ${DOCSDIR}/
	@cd ${WRKSRC}/../ && ${COPYTREE_SHARE} "doc rules" ${DOCSDIR}
.endif
.if !defined(SKIP_RULES)
	@${INSTALL_DATA} ${WRKDIR}/mod_security2.conf ${PREFIX}/${APACHEETCDIR}/Includes/
	@cd ${WRKSRCTOP} && ${PAX} -rw -pe -s +rules+mod_security2+ rules ${PREFIX}/${APACHEETCDIR}/Includes
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
