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

BROKEN=	Conlict with one of its dependency: devel/py-ll-core

RUN_DEPENDS=	${PYXML} \
		${PYTHON_PKGNAMEPREFIX}ll-core>=1.11.1:${PORTSDIR}/devel/py-ll-core \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}cssutils>=0.9.7:${PORTSDIR}/www/py-cssutils

USE_PYTHON=		-2.7
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
USE_BZIP2=		yes
PYDISTUTILS_PKGNAME=	ll-xist

.include <bsd.port.mk>
