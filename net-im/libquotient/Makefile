PORTNAME=	libquotient
DISTVERSION=	0.8.1.2
CATEGORIES=	net-im
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Matrix IM support library using Qt technologies
WWW=		https://github.com/quotient-im/libQuotient

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	lib${FLAVOR}keychain.so:security/qtkeychain@${FLAVOR} \
		libolm.so:security/olm

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++20-lang qt:${FLAVOR:S/qt//} tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	quotient-im
GH_PROJECT=	libQuotient
USE_QT=		${_USE_QT_${FLAVOR}}
CMAKE_ARGS=	${_CMAKE_ARGS_${FLAVOR}} \
		-DCMAKE_INSTALL_INCLUDEDIR:PATH=${_INCDIR_REL_${FLAVOR}}
CMAKE_ON=	Quotient_ENABLE_E2EE
CMAKE_OFF=	Quotient_INSTALL_TESTS

CONFLICTS=	libqmatrixclient\*

PLIST_SUB=	QUOTIENT_SUFFIX=${_QT_VER_SUFFIX_${FLAVOR}} \
		QUOTIENT_INCDIR=${_INCDIR_REL_${FLAVOR}} \
		QUOTIENT_QT5_ONLY=${_QT5_ONLY_${FLAVOR}}

# Flavorization
_USE_QT_qt5=		concurrent core gui multimedia network \
			buildtools:build qmake:build testlib:build
_USE_QT_qt6=		base
_CMAKE_ARGS_qt5=	-DBUILD_WITH_QT6:BOOL=FALSE
_CMAKE_ARGS_qt6=	-DBUILD_WITH_QT6:BOOL=TRUE
_INCDIR_REL_qt5=	include/QuotientQt5
_INCDIR_REL_qt6=	include/QuotientQt6
_QT_VER_SUFFIX_qt5=	#
_QT_VER_SUFFIX_qt6=	Qt6
_QT5_ONLY_qt5=		#
_QT5_ONLY_qt6=		"@comment "


.include <bsd.port.options.mk>

# Work around compiler bug, see pr: 272285
.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
USES+=		llvm
.endif

.include <bsd.port.mk>
