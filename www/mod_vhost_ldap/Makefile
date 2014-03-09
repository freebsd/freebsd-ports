# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_vhost_ldap
PORTVERSION=	2.0.8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=pool/main/m/mod-vhost-ldap
DISTNAME=	${PORTNAME:S/_/-/g}_${PORTVERSION}.orig
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Virtual Hosting from ldap built on top of mod_ldap

LICENSE=	APACHE20

USE_OPENLDAP=	yes

USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
AP_LIB+=	${LOCALBASE}/lib -lldap
AP_EXTRAS+=	-DMOD_VHOST_LDAP_VERSION=\\\"mod_vhost_ldap/${PORTVERSION}\\\"

PORTDOCS=	mod_vhost_ldap.schema vhost_ldap.conf COPYING

WRKSRC=		${WRKDIR}/${PORTNAME:S/_/-/g}-${PORTVERSION}

.if defined(PACKAGE_BUILDING)
IGNORE=		Requires support of LDAP in apache 2.x port
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
