# New ports collection makefile for:	py-amf
# Date created:				14 July 2008
# Whom:					Junji NAKANISHI <jun-g@daemonfreaks.com>
#
# $FreeBSD$

PORTNAME=	amf
PORTVERSION=	0.6
CATEGORIES=	www devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYDISTUTILS_PKGNAME}-${PORTVERSION}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	AMF support for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	PyAMF
PYEASYINSTALL_ARCHDEP=	yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 250
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/elementtree/__init__.py:${PORTSDIR}/devel/py-elementtree
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/uuid.py:${PORTSDIR}/devel/py-uuid
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst
.endif

.include <bsd.port.post.mk>
