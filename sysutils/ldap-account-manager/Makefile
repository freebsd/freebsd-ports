# New ports collection makefile for:   	ldap-account-manager
# Date created:				August, 2nd 2003
# Whom:                			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	ldap-account-manager
PORTVERSION=	2.7.0
CATEGORIES=	sysutils www
MASTER_SITES=	SF/${PNAME}
DISTNAME=	${PORTNAME:L}-${PORTVERSION}

MAINTAINER=	basil@vpm.net.ua
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

FETCH_CMD?=	/usr/bin/fetch -pRr
NO_BUILD=	yes
USE_GETTEXT=	yes
USE_PERL5=	yes
USE_PHP=	gettext hash iconv ldap mcrypt pcre session xml
WANT_PHP_WEB=	yes
DEFAULT_PHP_VER=	5

PNAME=		lam
PORTDOCS=	docs COPYING HISTORY INSTALL README copyright
LAMDATA=	config graphics help lib locale sess style templates tmp VERSION index.html
WWWDIR?=	${PREFIX}/www/${PNAME}
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

do-configure:
	@${RM} ${WRKSRC}/config/shells

do-install:
	-@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${LAMDATA}" ${WWWDIR}
.if !defined(NOPORTDOCS)
	-@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${DOCSDIR}
.endif

post-install:
	@if [ ! -f ${WWWDIR}/config/config.cfg ]; then \
	    ${CP} -p ${WWWDIR}/config/config.cfg_sample ${WWWDIR}/config/config.cfg ; \
	fi
	@if [ ! -f ${WWWDIR}/config/lam.conf ]; then \
	    ${CP} -p ${WWWDIR}/config/lam.conf_sample ${WWWDIR}/config/lam.conf ; \
	fi
	@${FIND} ${WWWDIR} -type f -exec ${CHMOD} 644 {} \;
	@${FIND} ${WWWDIR} -type d -exec ${CHMOD} 755 {} \;
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/config ${WWWDIR}/sess ${WWWDIR}/tmp
	@${CHMOD} 755 ${WWWDIR}/lib/lamdaemon.pl
	@${LN} -sf /etc/shells ${WWWDIR}/config/shells
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
