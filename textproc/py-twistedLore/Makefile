# New ports collection makefile for:	py-twistedLore
# Date created:		14 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	twistedLore
PORTVERSION=	12.0.0
CATEGORIES=	textproc python
MASTER_SITES=	http://twistedmatrix.com/Releases/Lore/${PORTVERSION:R}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TwistedLore-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Documentation generator with HTML and LaTeX support

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/twisted:${PORTSDIR}/devel/py-twistedCore
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Twisted_Lore

.include <bsd.port.mk>
