# Created by: Gerrit Beine <gerrit.beine@gmx.de>
# $FreeBSD$

PORTNAME=	xmlrpc
PORTVERSION=	1.1.2.r${SVN_REV}
CATEGORIES=	www devel python
MASTER_SITES=	http://www.sourcehosting.net/freebsd/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-r${SVN_REV}

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	Provides an XML-RPC interface to Trac

LICENSE=	BSD

SVN_REV=	13203

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/trunk
USE_ZIP=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
PYDISTUTILS_PKGNAME=	TracXMLRPC
PYDISTUTILS_PKGVERSION=	${PORTVERSION:C/.r${SVN_REV}//g}
PLIST_FILES=		%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.mk>
