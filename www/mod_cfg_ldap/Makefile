# New ports collection makefile for:	mod_cfg_ldap
# Date created:				Sun Oct 19
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_cfg_ldap
PORTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_//g}
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Allows you to keep your virtual host configuration in a LDAP directory

USE_APACHE=	YES
WITH_APACHE2=	YES
USE_OPENLDAP=	YES

APXS?=		${LOCALBASE}/sbin/apxs
LDAP_INC?=	${LOCALBASE}/include
LDAP_LIB?=	${LOCALBASE}/lib -lldap

PORTDOCS=	AUTHORS cfg_ldap.conf ChangeLog COPYING INSTALL \
		mod_cfg_ldap.schema README TODO

do-build:
	@(cd ${WRKSRC} && ${APXS} -I ${LDAP_INC} -L ${LDAP_LIB} -c ${PORTNAME}.c)

do-install:
	@(cd ${WRKSRC} && ${APXS} -n ${PORTNAME:S/mod_//} -A -i ${PORTNAME}.la)
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.   endfor
.endif

.include <bsd.port.mk>
