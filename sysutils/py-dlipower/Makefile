# Created by: M. Warner Losh <imp@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dlipower
PORTVERSION=	0.7.165
PORTEPOCH=	2
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	imp@FreeBSD.org
COMMENT=	CLI interface to Digital Logger's (DLI) Power Strips

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=4.0:www/py-beautifulsoup@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.0:www/py-requests@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9:devel/py-six@${FLAVOR}

USES=		python shebangfix
SHEBANG_FILES=	scripts/fence_dli
USE_PYTHON=	autoplist concurrent distutils
NO_ARCH=	yes

.include <bsd.port.mk>
