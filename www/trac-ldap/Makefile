# New ports collection makefile for: trac-ldap
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ldap
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://www.gerritbeine.de/download/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LDAP extenstions for Trac

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		${PYTHON_PKGNAMEPREFIX}ldap2>=2.3.1:${PORTSDIR}/net/py-ldap2

WRKSRC=		${WRKDIR}/${PORTNAME}plugin
NO_BUILD=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}dev PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
