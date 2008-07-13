# New ports collection makefile for:   	ldap-account-manager
# Date created:				August, 2nd 2003
# Whom:                			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	ldap-account-manager
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	SF/${PNAME}
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	basil@vpm.net.ua
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

NO_BUILD=	yes
USE_GETTEXT=	yes
USE_PERL5=	yes
USE_PHP=	pcre xml gettext session mcrypt ldap mhash iconv
WANT_PHP_WEB=	yes

PNAME=		lam
PORTDOCS=	docs COPYING HISTORY INSTALL README
LAMDATA=	index.html VERSION config graphics help lib locale sess style templates tmp
WWWDIR?=	${PREFIX}/www/${PNAME}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-configure:
	@${RM} ${WRKSRC}/config/shells

do-install:
	-@${MKDIR} ${WWWDIR}
.for i in ${LAMDATA}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${i} ${WWWDIR}
.endfor
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${DOCSDIR}
.for j in ${PORTDOCS}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${j} ${DOCSDIR}
.endfor
.endif
	@[ -e ${WWWDIR}/config/config.cfg ] || ${INSTALL_DATA} ${WRKSRC}/config/config.cfg_sample ${WWWDIR}/config/config.cfg
	@[ -e ${WWWDIR}/config/lam.conf   ] || ${INSTALL_DATA} ${WRKSRC}/config/lam.conf_sample   ${WWWDIR}/config/lam.conf

post-install:
	@${ECHO_MSG} "===> Setting correct permissions"
	@${FIND} ${WWWDIR} -type f -exec ${CHMOD} 644 {} \;
	@${FIND} ${WWWDIR} -type d -exec ${CHMOD} 755 {} \;
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/config ${WWWDIR}/sess ${WWWDIR}/tmp
	@${LN} -sf /etc/shells ${WWWDIR}/config/shells
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
