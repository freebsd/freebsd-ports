# $FreeBSD$

PORTNAME=	RestrictedPython
PORTVERSION=	3.6.0
PORTREVISION=	1
CATEGORIES=	security python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Restricted execution environment for Python

LICENSE=	ZPL21

USE_PYTHON=	2
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} >= 270
PLIST_SUB+=	PYTHON27=""
.else
PLIST_SUB+=	PYTHON27="@comment "
.endif

.include <bsd.port.post.mk>
