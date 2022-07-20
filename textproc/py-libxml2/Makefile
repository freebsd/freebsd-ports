PORTREVISION=	5
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python interface for XML parser library for GNOME
MASTERDIR=	${.CURDIR}/../libxml2

USES+=		gettext-runtime gnome python shebangfix
USE_GNOME=	libxml2
USE_PYTHON=	autoplist distutils
SHEBANG_FILES=	*.py doc/*.py python/*.py python/tests/*.py

OPTIONS_EXCLUDE=	${OPTIONS_DEFINE}

# Tell master port we're a slave port
LIBXML2_SLAVE=	python
# Grab pkg-descr from slave port
DESCR=		${.CURDIR}/pkg-descr

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

# Don't append pkg-plist from master port
PLIST=

DOCSDIR=	${PREFIX}/share/doc/py-libxml2
EXAMPLESDIR=	${PREFIX}/share/examples/py-libxml2

do-configure:

.include "${MASTERDIR}/Makefile"
