# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldap2
PORTVERSION=	2.0.0pre18
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-ldap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-ldap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An LDAP module for python, for OpenLDAP2

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S=-src==}
USE_OPENLDAP=	yes
USE_REINPLACE=	yes

do-configure:
	@${REINPLACE_CMD} -e "s=/usr/local/openldap-REL_ENG_2_1/lib=${LOCALBASE}/lib=" \
		-e "s=/usr/local/openldap-REL_ENG_2_1/include=${LOCALBASE}/include=" \
		-e "s=ldap_r lber sasl2 ssl crypto=ldap_r lber ssl crypto=" \
		${WRKSRC}/setup.cfg

.include <bsd.port.mk>
