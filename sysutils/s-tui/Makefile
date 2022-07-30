PORTNAME=	s-tui
PORTVERSION=	1.1.4
CATEGORIES=	sysutils python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Stress Terminal UI, Terminal-based CPU stress and monitoring utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=5.9.1:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=2.0.1:devel/py-urwid@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils noflavors

NO_ARCH=	yes

.include <bsd.port.mk>
