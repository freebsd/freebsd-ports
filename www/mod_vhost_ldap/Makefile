# New ports collection makefile for:	mod_vhost_ldap
# Date created:				Sep 10 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_vhost_ldap
PORTVERSION=	0.2.4
CATEGORIES=	www
MASTER_SITES=	http://alioth.debian.org/download.php/1113/
DIST_SUBDIR=	apache2
USE_BZIP2=	YES
DISTNAME=	${PORTNAME:S/_/-/g}-${PORTVERSION}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Virtual Hosting from ldap built on top of mod_ldap

WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
USE_OPENLDAP=	YES
AP_LIB+=	${LOCALBASE}/lib -lldap
AP_EXTRAS+=	-DMOD_VHOST_LDAP_VERSION=\\\"mod_vhost_ldap/${PORTVERSION}\\\"

PORTDOCS=	mod_vhost_ldap.schema vhost_ldap.conf COPYING

.if defined(PACKAGE_BUILDING)
IGNORE=		Requires support of LDAP in apache 2.0.x port
.endif

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache20/Makefile.modules.3rd"
post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.include <bsd.port.post.mk>
