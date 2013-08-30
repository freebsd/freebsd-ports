# New ports collection makefile for: trac-batchmodify
# Date created:                      Jan 29 2009
# Whom:                              Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	batchmodify
PORTVERSION=	0.8.0.9694
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Enables users to modify several tickets together at once

RUN_DEPENDS+=	trac>=0.12:${PORTSDIR}/www/trac

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.12/trunk
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=    BatchModify
PYDISTUTILS_PKGVERSION= ${PORTVERSION:R}_trac0.12
PLIST_SUB+=	EGGVERSION=${PORTVERSION:R} PYTHONVERSION=${PYTHON_VER}
PYDISTUTILS_NOEGGINFO=	yes
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/BatchModify-%%EGGVERSION%%_trac0.12-py%%PYTHONVERSION%%.egg

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
