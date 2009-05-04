# New ports collection makefile for: trac-tocmacro
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	tocmacro
PORTVERSION=	11.0.0.3
CATEGORIES=	www devel python
MASTER_SITES=	http://people.freebsd.org/~mm/trac/
PKGNAMEPREFIX=	trac-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Table of contents macro

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracTocMacro
PLIST_SUB+=	PORTVERSION=${PORTVERSION} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
