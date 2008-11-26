# New ports collection makefile for: trac-revtree
# Date created:                      Nov 10 2008
# Whom:                              glarkin
#
# $FreeBSD$
#

PORTNAME=	revtree
PORTVERSION=	0.6.2
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Graphical representation of an SVN repository

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USE_PYTHON=	2.3+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracRevtreePlugin
PYDISTUTILS_PKGVERSION=	${PORTVERSION}dev
PLIST_SUB+=	EGGVERSION="${PORTVERSION}dev" PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
