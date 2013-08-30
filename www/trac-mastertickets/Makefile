# New ports collection makefile for: trac-mastertickets
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	mastertickets
PORTVERSION=	3.0.2
CATEGORIES=	www devel python
MASTER_SITES=	http://mirrors.redv.com/pub/trac/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	coderanger-trac-${PORTNAME}-43a7537

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Support for ticket dependencies

RUN_DEPENDS+=	trac>=0.12:${PORTSDIR}/www/trac

WRKSRC=			${WRKDIR}/${DISTNAME}

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracMasterTickets
PYDISTUTILS_NOEGGINFO=	yes

PLIST_SUB+=		PORTVERSION=${PORTVERSION} \
			PYTHONVERSION=${PYTHON_VER}
PLIST_FILES+=		%%PYTHON_SITELIBDIR%%/TracMasterTickets-%%PORTVERSION%%-py%%PYTHONVERSION%%.egg

.include <bsd.port.mk>
