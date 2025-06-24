PORTNAME=	qgpgme
PORTVERSION=	2.0.0
CATEGORIES=	security
MASTER_SITES=	GNUPG
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	GnuPG Made Easy (GPGME) Qt bindings
WWW=		https://gnupg.org/software/gpgme/index.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp

FLAVORS=	qt6 qt5
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake:testing compiler:c++17-lang pkgconfig \
		qt:${FLAVOR:S|qt||} tar:xz
USE_LDCONFIG=	yes
_USE_QT_qt5=	core buildtools:build qmake:build testlib:test
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ON=	BUILD_WITH_${FLAVOR:tu}
_CMAKE_OFF_qt5=	BUILD_WITH_QT6
_CMAKE_OFF_qt6=	BUILD_WITH_QT5
CMAKE_OFF=	BUILD_TESTING \
		${_CMAKE_OFF_${FLAVOR}}

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
_PLIST_SUB_qt5=	QGPGME_CMAKE_SUFFIX="" \
		QGPGME_LIB_SUFFIX=""
_PLIST_SUB_qt6=	QGPGME_CMAKE_SUFFIX="Qt6" \
		QGPGME_LIB_SUFFIX="qt6"
PLIST_SUB=	QGPGME_INCLUDE_SUFFIX="${FLAVOR}" \
		${_PLIST_SUB_${FLAVOR}}

OPTIONS_DEFINE=		DOXYGEN

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Doxygen

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	cd ${BUILD_WRKSRC}/doc/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html
	@${FIND} -P ${STAGEDIR}${DOCSDIR} -type f 2>/dev/null | \
		${SED} -ne 's|^${STAGEDIR}${PREFIX}/||p' >> ${TMPPLIST}

.include <bsd.port.mk>
