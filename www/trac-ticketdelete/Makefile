# New ports collection makefile for: trac-ticketdelete
# Date created:                      May 18 2007
# Whom:                              Gerrit Beine <gerrit.beine@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ticketdelete
PORTVERSION=	2.0.3543
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://people.freebsd.org/~mm/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ticket and ticket change deletion

DEPRECATED=	Functionality of this plugin has been incorporated into Trac 0.12
EXPIRATION_DATE=2012-06-13

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USE_PYTHON=	-2.7
USE_PYDISTUTILS=        easy_install
PYDISTUTILS_PKGNAME=    TracTicketDelete
PYDISTUTILS_PKGVERSION= ${PORTVERSION:R}
PLIST_SUB+=	PORTVERSION=${PORTVERSION:R} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

.include <bsd.port.mk>
