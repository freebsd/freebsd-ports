PORTNAME=	libxml2-python
PORTREVISION=	0
CATEGORIES=	textproc gnome python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	# blank, to override the one in the master port

COMMENT=	Python interface for XML parser library for GNOME

DEPRECATED=	Using these bindings is discouraged by upstream, see https://gitlab.gnome.org/GNOME/libxml2/-/issues/891 and https://gitlab.gnome.org/GNOME/libxml2/-/issues/924
EXPIRATION_DATE=2026-03-31

# doxygen already listed in libxml2-core/Makefile
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	libxml2=${PORTVERSION}:textproc/libxml2 # docs

USES+=		gnome localbase python shebangfix
USE_GNOME=	libxml2 # pulls in libxml2-core
USE_PYTHON=	autoplist distutils # generator.py not found in PEP-517 environment
SHEBANG_GLOB=	*.py*

# work around Makefile not reliably defining doxygen --without-docs but --with-python
MAKE_ARGS+=	DOXYGEN=${LOCALBASE}/bin/doxygen

# CPPFLAGS addition required so that this port can build with an older libxml2 installed
CPPFLAGS+=	-I${WRKSRC}/include

DOCSDIR=	${PREFIX}/share/doc/libxml2-python
EXAMPLESDIR=	${PREFIX}/share/examples/libxml2-python
MASTERDIR=	${.CURDIR}/../libxml2-core

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
TEST_WRKSRC=	${BUILD_WRKSRC}

# Grab pkg-descr from slave port
DESCR=		${.CURDIR}/pkg-descr

# Don't append pkg-plist from master port
PLIST=

OPTIONS_EXCLUDE=	${OPTIONS_DEFINE:NPYTHON} ${OPTIONS_GROUP_LEGACY}
OPTIONS_SLAVE=		PYTHON

pre-build:
	( cd ${WRKSRC}     && ${DO_MAKE_BUILD} libxml2.la && \
	  cd ${WRKSRC}/doc && ${DO_MAKE_BUILD} )

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_LIBDIR}/site-packages/libxml2mod${PYTHON_SOABI}.so

.include "${MASTERDIR}/Makefile"
