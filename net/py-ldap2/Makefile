# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldap2
PORTVERSION=	2.0.0pre04
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-ldap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ldap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An LDAP module for python, for OpenLDAP2

LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S=-src==}

#class = OpenLDAP2
#library_dirs = /usr/local/openldap2/lib
#include_dirs = /usr/local/openldap2/include
#libs = lber ldap resolv
do-configure:
	@${MV} ${WRKSRC}/setup.cfg ${WRKSRC}/setup.cfg.sed
	${SED} -e "s=/usr/local/openldap2/lib=${LOCALBASE}/lib=" \
		-e "s=/usr/local/openldap2/include=${LOCALBASE}/include=" \
		-e "s=lber ldap resolv=lber ldap=" \
		${WRKSRC}/setup.cfg.sed > ${WRKSRC}/setup.cfg

.include <bsd.port.mk>
