# New ports collection makefile for:   	LDAP-Account-Manager
# Date created:				August, 2nd 2003
# Whom:                			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	LDAP-Account-Manager
PORTVERSION=	0.4.6
PORTREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lam
DISTNAME=	${PORTNAME:L}_${PORTVERSION}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota\
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

USE_PHP=	gettext session mcrypt ldap
WANT_PHP_WEB=	yes
NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

WWW_ROOT?=	www/lam
PLIST_SUB+=	WWWROOT=${WWW_ROOT}
WWW_DATA=	index.html config graphics help lib locale sess style templates tmp
MYPORTDOCS=	HISTORY README TODO docs/*
PORTDOCS=	*
LAM_SCRIPTS=	lib/createntlm.pl lib/lamdaemon.pl

do-configure:
	@${RM} ${WRKSRC}/config/shells

do-install:
	@${MKDIR} ${PREFIX}/${WWW_ROOT}
	@cd ${WRKSRC} && ${TAR} cf - ${WWW_DATA} | ${TAR} xf - -C ${PREFIX}/${WWW_ROOT} 
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${MYPORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${PREFIX}/${WWW_ROOT}/tmp
	@[ -e ${PREFIX}/${WWW_ROOT}/config/config.cfg ] || \
			${INSTALL_DATA} ${WRKSRC}/config/config.cfg_sample ${PREFIX}/${WWW_ROOT}/config/config.cfg
	@[ -e ${PREFIX}/${WWW_ROOT}/config/lam.conf ] || \
			${INSTALL_DATA} ${WRKSRC}/config/lam.conf_sample ${PREFIX}/${WWW_ROOT}/config/lam.conf
	@${ECHO_MSG} "===> Setting correct permissions"
	@${FIND} ${PREFIX}/${WWW_ROOT} -type f -exec ${CHMOD} 644 {} \;
	@${FIND} ${PREFIX}/${WWW_ROOT} -type d -exec ${CHMOD} 755 {} \;
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${WWW_ROOT}/*
	@cd ${PREFIX}/${WWW_ROOT} ; ${CHMOD} 755 ${LAM_SCRIPTS}
	@${LN} -sf /etc/shells ${PREFIX}/${WWW_ROOT}/config/shells

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
