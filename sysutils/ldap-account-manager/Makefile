# New ports collection makefile for:   	LDAP-Account-Manager
# Date created:				August, 2nd 2003
# Whom:                			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	LDAP-Account-Manager
PORTVERSION=	1.0.1
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lam
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	dimma@higis.ru
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota\
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

USE_PHP=	pcre xml gettext session mcrypt ldap
WANT_PHP_WEB=	yes
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

WWW_ROOT?=	www/lam
WWWOWN?=	www
WWWGRP?=	www
PKGINSTALL=	${WRKDIR}/pkg-install
PLIST_SUB+=	WWWROOT=${WWW_ROOT}
WWW_DATA=	index.html config graphics help lib locale sess style templates tmp
MYPORTDOCS=	HISTORY README TODO COPYING INSTALL VERSION copyright docs/*
LAM_SCRIPTS=	lib/lamdaemon.pl
PORTDOCS=	*

do-configure:
	@${RM} ${WRKSRC}/config/shells

do-install:
	@${MKDIR} ${PREFIX}/${WWW_ROOT}
	@cd ${WRKSRC} && ${TAR} cf - ${WWW_DATA} | ${TAR} xf - -C ${PREFIX}/${WWW_ROOT}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${TAR} cf - ${MYPORTDOCS} | ${TAR} xf - -C ${DOCSDIR}
.endif
	@${MKDIR} ${PREFIX}/${WWW_ROOT}/tmp
	@[ -e ${PREFIX}/${WWW_ROOT}/config/config.cfg ] || \
			${INSTALL_DATA} ${WRKSRC}/config/config.cfg_sample ${PREFIX}/${WWW_ROOT}/config/config.cfg
	@[ -e ${PREFIX}/${WWW_ROOT}/config/lam.conf ] || \
			${INSTALL_DATA} ${WRKSRC}/config/lam.conf_sample ${PREFIX}/${WWW_ROOT}/config/lam.conf
post-patch:
	@${SED} -e "s;%%WWWOWN%%;${WWWOWN};g" \
		-e "s;%%WWWGRP%%;${WWWGRP};g" \
		-e "s;%%WWW_ROOT%%;${WWW_ROOT};g" \
		${.CURDIR}/pkg-install > ${PKGINSTALL}

post-install:
	@${ECHO_MSG} "===> Setting correct permissions"
	@${FIND} ${PREFIX}/${WWW_ROOT} -type f -exec ${CHMOD} 644 {} \;
	@${FIND} ${PREFIX}/${WWW_ROOT} -type d -exec ${CHMOD} 755 {} \;
	@cd ${PREFIX}/${WWW_ROOT} ; ${CHMOD} 755 ${LAM_SCRIPTS}
	@${LN} -sf /etc/shells ${PREFIX}/${WWW_ROOT}/config/shells
	@PKG_PREFIX=${PREFIX} WWWOWN=${WWWOWN} WWWGRP=${WWWGRP} WWW_ROOT=${WWW_ROOT} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
