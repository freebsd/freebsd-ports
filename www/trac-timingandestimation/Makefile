# New ports collection makefile for: trac-timingandestimation
# Date created:                      February 26 2010
# Whom:                              Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	timingandestimation
PORTVERSION=	1.0.8b
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}
USE_ZIP=	yes

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Add estimation and time tracking functionality to Trac

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/branches/trac0.12-Permissions
NO_BUILD=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION:S/.r/_r/} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
