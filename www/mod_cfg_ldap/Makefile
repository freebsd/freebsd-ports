# New ports collection makefile for:	mod_cfg_ldap
# Date created:				Sun Oct 19
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_cfg_ldap
PORTVERSION=	1.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_//g}
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows you to keep your virtual host configuration in a LDAP directory

WANT_APACHE=	2
USE_OPENLDAP=	YES
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES

LDAP_INC?=	${LOCALBASE}/include
LDAP_LIB?=	${LOCALBASE}/lib -lldap
AP_INC+=	${LDAP_INC}
AP_LIB+=	${LDAP_LIB}

PORTDOCS=	AUTHORS cfg_ldap.conf ChangeLog COPYING INSTALL \
		mod_cfg_ldap.schema README TODO

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.post.mk>
