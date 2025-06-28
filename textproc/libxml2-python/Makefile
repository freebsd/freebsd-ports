PORTNAME=	libxml2-python
PORTREVISION=	0
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python interface for XML parser library for GNOME
MASTERDIR=	${.CURDIR}/../libxml2

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}

USES+=		gettext-runtime gnome python shebangfix
USE_GNOME=	libxml2
USE_PYTHON=	autoplist distutils # generator.py not found in PEP-517 environment
SHEBANG_GLOB=	*.py*

OPTIONS_EXCLUDE=	${OPTIONS_DEFINE} ${OPTIONS_GROUP_LEGACY}

# Tell master port we're a slave port
LIBXML2_SLAVE=	python
# Grab pkg-descr from slave port
DESCR=		${.CURDIR}/pkg-descr

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

# Don't append pkg-plist from master port
PLIST=

DOCSDIR=	${PREFIX}/share/doc/libxml2-python
EXAMPLESDIR=	${PREFIX}/share/examples/libxml2-python

.include "${MASTERDIR}/Makefile"
