# New ports collection makefile for:   	LDAP-Account-Manager
# Date created:				August, 2nd 2003
# Whom:                			Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	LDAP-Account-Manager
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lam
DISTNAME=	${PORTNAME:L}_${PORTVERSION}

MAINTAINER=	clement@FreeBSD.org
COMMENT=	Webfrontend for managing accounts stored in an OpenLDAP server

RUN_DEPENDS=	${LOCALBASE}/${MOD_DIR}/libphp4.so:${PORTSDIR}/lang/php4-horde \
		${SITE_PERL}/${PERL_ARCH}/Quota.pm:${PORTSDIR}/sysutils/p5-Quota\
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

NO_BUILD=	YES
WRKSRC=		${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

.if defined(WITH_APACHE2)
MOD_DIR=	libexec/apache2
.else
MOD_DIR=	libexec/apache
.endif

WWW_ROOT?=	www/lam
PLIST_SUB+=	WWWROOT=${WWW_ROOT}
WWW_DIR=	config graphics help lib locale sess style templates
MYPORTDOCS=	HISTORY README TODO docs/README.fpdf docs/README.openldap \
		docs/README.shells docs/README.hosts docs/README.security \
		docs/README.lamdaemon.pl
WWW_OWNED=	sess tmp config config config/profiles config/profiles/groups \
		config/profiles/groups/default.prg config/profiles/hosts \
		config/profiles/hosts/default.prh config/profiles/users \
		config/profiles/users/default.pru config/language config/shells \
		config/config.cfg config/lam.conf

LAM_SCRIPTS=	lib/createntlm.pl lib/lamdaemon.pl

CVS_DIRS=	${WRKSRC}/lib/font/CVS ${WRKSRC}/lib/font/makefont/CVS

post-extract:
	@${RM} -fr ${CVS_DIRS}

do-install:
	@${MKDIR} ${PREFIX}/${WWW_ROOT}
	@${INSTALL_DATA} ${WRKSRC}/index.html ${PREFIX}/${WWW_ROOT}
.for DIR in ${WWW_DIR}
	@${MKDIR} ${PREFIX}/${WWW_ROOT}/${DIR}
	@${CP} -Rf ${WRKSRC}/${DIR} ${PREFIX}/${WWW_ROOT}
.endfor
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
	@cd ${PREFIX}/${WWW_ROOT} ; ${CHOWN} ${WWWOWN}:${WWWGRP} ${WWW_OWNED}
	@cd ${PREFIX}/${WWW_ROOT} ; ${CHMOD} 755 ${LAM_SCRIPTS}

post-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  To use LDAP-account-manager, you have to install"
	@${ECHO_MSG} "  and set up Samba 2.x or 3.x schemas."
	@${ECHO_MSG} "  Like this :"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/core.schema"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/cosine.schema"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/inetorgperson.schema"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/nis.schema"
	@${ECHO_MSG} "     include       ${LOCALBASE}/etc/openldap/schema/samba.schema"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
