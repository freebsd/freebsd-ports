PORTNAME=	ohmu
DISTVERSION=	1.1.0
PORTREVISION=	7
CATEGORIES=	sysutils
MASTER_SITES=	PYPI

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to view space usage in your terminal
WWW=		https://gitlab.com/paul-nechifor/ohmu

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent optsuffix pep517

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^from past\.builtins import basestring$$/d' \
		-e 's/isinstance(\([^,]*\), basestring)/isinstance(\1, str)/g' \
		${WRKSRC}/ohmu/utils.py ${WRKSRC}/ohmu/test_fs.py
	@${REINPLACE_CMD} -e '/^from builtins import range$$/d' \
		${WRKSRC}/ohmu/views.py
	@${REINPLACE_CMD} -e '/future==0.15.2/d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
