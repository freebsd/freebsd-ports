# Created by: Trevor Caira <trevor@bitba.se>
# $FreeBSD$

PORTNAME=	selector
PORTVERSION=	0.10.1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WSGI request delegation (a.k.a. routing)

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}resolver>=0:devel/py-resolver@${FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

.include <bsd.port.mk>
