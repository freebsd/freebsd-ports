# ex:ts=8
# New ports collection makefile for:	XIST
# Date created:			Nov 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xist
PORTVERSION=	3.17.3
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://ftp.livinglogic.de/xist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ll-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An XML-based extensible HTML generator

RUN_DEPENDS=	${PYXML} \
		${PYTHON_PKGNAMEPREFIX}ll-core>=1.11.1:${PORTSDIR}/devel/py-ll-core \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.7:${PORTSDIR}/www/py-cssutils

USE_PYTHON=		2.6+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
USE_BZIP2=		yes
PYDISTUTILS_PKGNAME=	ll-xist

.include <bsd.port.mk>
