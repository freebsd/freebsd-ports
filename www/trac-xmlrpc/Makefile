# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	xmlrpc
PORTVERSION=	1.0.6
PORTREVISION=	3
CATEGORIES=	www devel python
MASTER_SITES=	http://shuqun.com/files/ \
		LOCAL/glarkin
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-${PORTVERSION}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Provides an xml rpc interface to Trac

LICENSE=	BSD

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	TracXMLRPC
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
