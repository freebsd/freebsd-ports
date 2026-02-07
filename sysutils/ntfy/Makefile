PORTNAME=	ntfy
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0-14
PORTREVISION=	1
DISTVERSIONSUFFIX=	-g0e922fa
CATEGORIES=	sysutils deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utility for sending notifications on-demand, and when commands finish
WWW=		https://ntfy.readthedocs.io/en/latest/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}appdirs>0:devel/py-appdirs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>0:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	dschep
USE_PYTHON=	distutils noflavors autoplist

CONFLICTS_INSTALL=	sysutils/go-ntfy

NO_ARCH=	yes

post-patch:
# Fix build with Python 3.11
	@${REINPLACE_CMD} -e 's|getargspec|getfullargspec|' \
		${WRKSRC}/ntfy/__init__.py

.include <bsd.port.mk>
