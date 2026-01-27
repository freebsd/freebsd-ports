PORTNAME=	libxml2-python
PORTREVISION=	0
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python interface for XML parser library for GNOME
MASTERDIR=	${.CURDIR}/../libxml2

DEPRECATED=	Planned for removal in 2.16: https://gitlab.gnome.org/GNOME/libxml2/-/releases/v2.15.0

BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		doxygen:devel/doxygen

USES+=		gnome python shebangfix
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
TEST_WRKSRC=	${BUILD_WRKSRC}

# Don't append pkg-plist from master port
PLIST=

DOCSDIR=	${PREFIX}/share/doc/libxml2-python
EXAMPLESDIR=	${PREFIX}/share/examples/libxml2-python

pre-build:
#	( cd ${WRKSRC}     && ${DO_MAKE_BUILD} libxml2.la && \
#	  cd ${WRKSRC}/doc && ${DO_MAKE_BUILD} )
	cd ${WRKSRC}/doc && ${DO_MAKE_BUILD} DOXYGEN=doxygen

.include "${MASTERDIR}/Makefile"
