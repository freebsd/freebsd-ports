# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldap2
PORTVERSION=	2.0.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-ldap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ldap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An LDAP module for python, for OpenLDAP2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_OPENLDAP=	yes
USE_REINPLACE=	yes

do-configure:
	@${REINPLACE_CMD} -e "s=/opt/openldap-OPENLDAP_REL_ENG_2_2/lib=${LOCALBASE}/lib=" \
		-e "s=/opt/openldap-OPENLDAP_REL_ENG_2_2/include=${LOCALBASE}/include=" \
		-e "s=ldap_r lber ssl crypto sasl2=ldap_r lber ssl crypto=" \
		${WRKSRC}/setup.cfg

.include <bsd.port.mk>
