# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	customroadmap
PORTVERSION=	0.4.2348
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://people.freebsd.org/~mm/trac/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Custom roadmap plugin for trac

DEPRECATED=	Functionality of this plugin is available in the Trac core as of 0.11
EXPIRATION_DATE=2012-11-18

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.11
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracCustomRoadmap
PYDISTUTILS_PKGVERSION=	0.4
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
