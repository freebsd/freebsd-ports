# New ports collection makefile for:	ldapmodule
# Date created:		05.Jul 2000
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	ldap2
PORTVERSION=	CVS200201041716
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-ldap
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Python-LDAP-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org

LIB_DEPENDS=	ldap.2:${PORTSDIR}/net/openldap2
BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S=-src==}

#class = OpenLDAP2
#library_dirs = /usr/local/openldap2/lib
#include_dirs = /usr/local/openldap2/include
#libs = lber ldap resolv
do-configure:
	@${PERL5} -pi -e "s=/usr/local/openldap2/lib=${LOCALBASE}/lib=" \
		${WRKSRC}/setup.cfg
	@${PERL5} -pi \
		-e "s=/usr/local/openldap2/include=${LOCALBASE}/include=" \
		${WRKSRC}/setup.cfg
	@${PERL5} -pi -e "s=lber ldap resolv=lber ldap=" ${WRKSRC}/setup.cfg

do-build:
	cd ${WRKSRC} && python setup.py build

do-install:
	cd ${WRKSRC} && python setup.py install

.include <bsd.port.mk>
