PORTNAME=	compreffor
PORTVERSION=	0.5.3
CATEGORIES=	x11-fonts python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lantw44@gmail.com
COMMENT=	CFF table subroutinizer for FontTools
WWW=		https://github.com/googlefonts/compreffor

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_scm>=0:devel/py-setuptools_scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools_git_ls_files>=0:devel/py-setuptools_git_ls_files@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}fonttools>=4:print/py-fonttools@${PY_FLAVOR}

USES=		compiler:c++11-lang python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
