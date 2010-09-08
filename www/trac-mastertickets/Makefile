# New ports collection makefile for: trac-mastertickets
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	mastertickets
PORTVERSION=	3.0.1
CATEGORIES=	www devel python
MASTER_SITES=	http://dist.codelabs.ru/fbsd/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Support for ticket dependencies

RUN_DEPENDS+=	trac>=0.12:${PORTSDIR}/www/trac

WRKSRC=			${WRKDIR}/coderanger-trac-mastertickets-a72a4e2

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracMasterTickets
PYDISTUTILS_NOEGGINFO=	yes

PLIST_SUB+=		PORTVERSION=${PORTVERSION} \
			PYTHONVERSION=${_PYTHON_VERSION}
PLIST_FILES+=		%%PYTHON_SITELIBDIR%%/TracMasterTickets-%%PORTVERSION%%-py%%PYTHONVERSION%%.egg

.include <bsd.port.mk>
