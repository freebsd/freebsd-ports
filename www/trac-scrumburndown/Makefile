# New ports collection makefile for: trac-scrumburndown
# Date created:                      February 26 2010
# Whom:                              Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scrumburndown
PORTVERSION=	1.9.2
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A plugin to enable Scrum burndown chart capabilities

BUILD_DEPENDS+=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac \
		trac-timingandestimation>=0:${PORTSDIR}/www/trac-timingandestimation

WRKSRC=		${WRKDIR}/${PORTNAME}plugin
NO_BUILD=	yes
USE_PYTHON=	2.3+
USE_PYDISTUTILS=yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION:S/.r/_r/} PYTHONVERSION=${_PYTHON_VERSION}
PYDISTUTILS_NOEGGINFO=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
