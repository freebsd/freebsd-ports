# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	mako
PORTVERSION=	0.9.0
CATEGORIES=	textproc www python
MASTER_SITES=	http://www.makotemplates.org/downloads/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Mako-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Super-fast templating language in Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beaker>=1.1:${PORTSDIR}/www/py-beaker \
		${PYTHON_PKGNAMEPREFIX}MarkupSafe>=0.9.2:${PORTSDIR}/textproc/py-MarkupSafe \
		${PYTHON_PKGNAMEPREFIX}Babel>0:${PORTSDIR}/devel/py-babel
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_AUTOPLIST=	yes
PYDISTUTILS_PKGNAME=	Mako

.include <bsd.port.mk>
