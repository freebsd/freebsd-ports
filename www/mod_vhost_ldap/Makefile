# New ports collection makefile for:	mod_vhost_ldap
# Date created:				Sep 10 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_vhost_ldap
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1422/
DISTNAME=	${PORTNAME:S/_/-/g}-${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Virtual Hosting from ldap built on top of mod_ldap

MAKE_JOBS_SAFE=	yes

USE_BZIP2=	YES
USE_OPENLDAP=	YES

USE_APACHE=	20+
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
AP_LIB+=	${LOCALBASE}/lib -lldap
AP_EXTRAS+=	-DMOD_VHOST_LDAP_VERSION=\\\"mod_vhost_ldap/${PORTVERSION}\\\"

PORTDOCS=	mod_vhost_ldap.schema vhost_ldap.conf COPYING

WRKSRC=		${WRKDIR}/${PORTNAME:S/_/-/g}-${PORTVERSION}.0

.if defined(PACKAGE_BUILDING)
IGNORE=		Requires support of LDAP in apache 2.x port
.endif

post-install:
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}

.include <bsd.port.mk>
