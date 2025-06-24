PORTNAME=	gpg
PORTVERSION=	2.0.0
CATEGORIES=	security python
MASTER_SITES=	GNUPG/gpgmepy
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	gpgmepy-${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Gpgme Python bindings

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BUILD_DEPENDS=	swig:devel/swig \
		${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

USES=		gmake pkgconfig python:3.9+ tar:bzip2
USE_PYTHON=	autoplist pep517

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	BSD_PYTHON="${PYTHON_CMD}" \
		BSD_PYTHON_VERSION="${PYTHON_VER}"
TEST_TARGET=	check

# Link src to the project name defined in pyproject.toml to deal with Python
# conventions. This is done in the project build system, but we're just using
# the configure part of the autotools and letting the FreeBSD python USES do
# the main build.
pre-build:
	(cd ${BUILD_WRKSRC} && ${LN} -sf src ${PORTNAME})

# Avoid patching the src 'copystamp' target, which tries to copy several files
# to their original location, causing errors. ${BUILD_WRKSRC}/copystamp just
# has to exist for the port 'test' target to function for our purposes.
pre-test:
	${TOUCH} ${BUILD_WRKSRC}/copystamp

.include <bsd.port.mk>
