# Created by: Clement Laforet <sheepkiller@cultdeadsheep.org>
# $FreeBSD$

PORTNAME=	mod_cfg_ldap
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	SF/modcfgldap/${PORTNAME}/${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows you to keep your virtual host configuration in a LDAP directory


USE_APACHE=	22+
USE_OPENLDAP=	yes
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

LDAP_INC?=	${LOCALBASE}/include
LDAP_LIB?=	${LOCALBASE}/lib -lldap
AP_INC+=	${LDAP_INC}
AP_LIB+=	${LDAP_LIB}

PORTDOCS=	AUTHORS cfg_ldap.conf ChangeLog COPYING INSTALL \
		mod_cfg_ldap.schema README TODO

NO_STAGE=	yes
post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
