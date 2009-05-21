# New ports collection makefile for:	mod_auth_ldap
# Date created:				07 June 2008
# Whom:					Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	mod_auth_ldap
PORTVERSION=	2.12
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.muquit.com/muquit/software/mod_auth_ldap/ \
		LOCAL
MASTER_SITE_SUBDIR=	jadawin
DISTNAME=	modauthldap_apache2

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Apache module to authenticate against an LDAP directory

MAKE_JOBS_SAFE=  yes

USE_OPENLDAP=	yes
USE_APACHE=	2.0+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SHORTMODNAME=	auth_ldap
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-dir=${LOCALBASE} --with-ssl=no
MAKE_ARGS+=	APXS=${APXS}

PORTDOCS=	README mod_auth_ldap_apache2.html ssl_tls.html

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
