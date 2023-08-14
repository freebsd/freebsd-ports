PORTNAME=	kdsoap
DISTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	www
# It's on GitHub, but KDAB uploads tidy release tarballs,
# so do NOT USE_GITHUB, but do write out the variables.
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${PORTNAME}-${DISTVERSION}/
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++/Qt SOAP framework
WWW=		https://github.com/KDAB/KDSoap

# The software is partly under (LGPL21 | GPL2 | GPL3 ), and partly
# under AGPLv3. We choose LGPL21 and AGPLv3, since that's easiest
# to express in a ports Makefile.
LICENSE=	LGPL21 AGPLv3
LICENSE_COMB=	multi

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++11-lang localbase pkgconfig qt:${FLAVOR:S/qt//}
# No USE_GITHUB, but pretty close
GH_ACCOUNT=	KDAB
GH_PROJECT=	KDSoap
USE_LDCONFIG=	yes
USE_QT=		${_USE_QT_${FLAVOR}}
# KDSoap upstream does not support co-installability properly. To mitigate this,
# install the headers to a prefixed location.
CMAKE_ARGS=	${_CMAKE_ARGS_${FLAVOR}} \
		-DINSTALL_INCLUDE_DIR:PATH=${PREFIX}/${_KDSOAP_INCDIR}


PLIST_SUB=	SOVER=${DISTVERSION} \
		KDSOAP_INCDIR=${_KDSOAP_INCDIR} \
		KDSOAP_SUFFIX=${_KDSOAP_SUFFIX} \
		KDSOAP_QT5_ONLY=${_KDSOAP_QT5_ONLY}

# Flavor handling
_CMAKE_ARGS_qt5=	-DKDSoap_QT6:BOOL=FALSE
_CMAKE_ARGS_qt6=	-DKDSoap_QT6:BOOL=TRUE
_USE_QT_qt5=	core network widgets xml \
		buildtools:build linguisttools:build qmake:build
_USE_QT_qt6=	base
_KDSOAP_INCDIR=	include/KDSoap${FLAVOR:S/qt//}
_KDSOAP_SUFFIX=	${_KDSOAP_SUFFIX_${FLAVOR}}
_KDSOAP_SUFFIX_qt6=	-qt6
_KDSOAP_QT5_ONLY_qt6=	"@comment "
_KDSOAP_QT5_ONLY=	${_KDSOAP_QT5_ONLY_${FLAVOR}}


.include <bsd.port.mk>
