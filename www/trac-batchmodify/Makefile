# New ports collection makefile for: trac-batchmodify
# Date created:                      Jan 29 2009
# Whom:                              Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	batchmodify
PORTVERSION=	0.2.0.4447
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Enables users to modify several tickets together at once

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=    BatchModify
PYDISTUTILS_PKGVERSION= ${PORTVERSION:R}
PLIST_SUB+=	EGGVERSION=${PORTVERSION:R} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
