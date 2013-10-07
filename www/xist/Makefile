# Created by: ijliao
# $FreeBSD$

PORTNAME=	xist
PORTVERSION=	3.25
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP \
		http://ftp.livinglogic.de/xist/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ll-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML-based extensible HTML generator

RUN_DEPENDS=	${PYXML} \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.7:${PORTSDIR}/www/py-cssutils

CONFLICTS_INSTALL=	py*-ll-core-1*

USE_PYTHON=		-2.7
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
USE_BZIP2=		yes
PYDISTUTILS_PKGNAME=	ll-xist

NO_STAGE=	yes
.include <bsd.port.mk>
