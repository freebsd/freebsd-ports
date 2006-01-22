# New ports collection makefile for:	drupal-ldap_integration
# Date created:				12 January 2006
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ldap_integration
DISTVERSION=	${DRUPVERSION}
PORTREVISION=	20060117
CATEGORIES=	security www
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks
PKGNAMEPREFIX=	drupal-
DIST_SUBDIR=	drupal

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	LDAP user authentication for the Drupal CMS

RUN_DEPENDS=	${LOCALBASE}/${DRUPDIR}/index.php:${PORTSDIR}/www/drupal

USE_PHP=	ldap

NO_BUILD=	yes

DOCSDIR=	${PREFIX}/${DRUPDIR}/doc/${PORTNAME}
DRUPMODDIR=	${DRUPDIR}/modules

WRKSRC=		${WRKDIR}/${PORTNAME}
MODULE_FILES=	ldap_integration.module \
		ldap_integration/LDAPInterface.php \
		zcallbacks.module
MODULE_CONF_FILES=	ldap_integration/conf.php
MODULE_CONF_DIRS=	ldap_integration
DOC_FILES=	CHANGES.txt LICENSE.txt README.txt

.if defined(MODULE_CONF_FILES)
SUB_FILES=	pkg-install
SUB_LIST+=	CONF_FILES=${MODULE_CONF_FILES:C|^|${DRUPMODDIR}/|} \
		CONF_DIRS=${MODULE_CONF_DIRS:C|^|${DRUPMODDIR}/|}
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${PKGINSTALL}
.endif

PLIST_SUB+=	DRUPMODDIR=${DRUPMODDIR}
PLIST_FILES+=	${MODULE_FILES:C|^|%%DRUPMODDIR%%/|}
PLIST_FILES+=	${MODULE_CONF_FILES:C|^|%%DRUPMODDIR%%/|:C|$|-dist|}
PLIST_DIRS+=	${MODULE_DIRS:C|^|%%DRUPMODDIR%%/|}
.if !defined(NOPORTDOCS)
PLIST_FILES+=	${DOC_FILES:C|^|%%DOCSDIR%%/|}
PLIST_DIRS+=	%%DOCSDIR%%
.endif

.if !defined(DRUPDIR)
pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define DRUPDIR to override default of 'www/drupal'."
	@${ECHO_MSG} ""
.endif

DRUPDIR?=	www/drupal
DRUPVERSION?=	4.6.0

do-install:
.if defined(MODULE_CONF_DIRS)
	@${MKDIR} ${MODULE_CONF_DIRS:C|^|${PREFIX}/${DRUPMODDIR}/|}
.endif
.if defined(MODULE_DIRS)
	@${MKDIR} ${MODULE_DIRS:C|^|${PREFIX}/${DRUPMODDIR}/|}
.endif
.for f in ${MODULE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DRUPMODDIR}/${f}
.endfor
.for f in ${MODULE_CONF_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DRUPMODDIR}/${f}-dist
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/${f}
.endfor
.endif

.if defined(MODULE_CONF_FILES)
post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
