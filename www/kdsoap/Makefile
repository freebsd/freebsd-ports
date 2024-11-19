PORTNAME=	kdsoap
DISTVERSION=	2.2.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/KDAB/KDSoap/releases/download/${PORTNAME}-${DISTVERSION}/
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	C++/Qt SOAP framework
WWW=		https://github.com/KDAB/KDSoap

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

FLAVORS=	qt5 qt6
FLAVOR?=	qt5

USES=		cmake compiler:c++${"${FLAVOR:Mqt6}" != "":?17:11}-lang \
		qt:${FLAVOR:S/qt//}
USE_LDCONFIG=	yes
_USE_QT_qt5=	core network xml \
		buildtools:build qmake:build
_USE_QT_qt6=	base
USE_QT=		${_USE_QT_${FLAVOR}}

CMAKE_ARGS=	-DKDSoap_QT6:BOOL=${"${FLAVOR:Mqt6}" != "":?TRUE:FALSE}
CMAKE_OFF=	KDSoap_EXAMPLES

PLIST_SUB=	SOVER=${DISTVERSION} \
		KDSOAPCLIENT_INCDIR_SUBDIR=${"${FLAVOR:Mqt6}" != "":?KDSoapClient-Qt6/:} \
		KDSOAPSERVER_INCDIR_SUBDIR=${"${FLAVOR:Mqt6}" != "":?KDSoapServer-Qt6/:} \
		KDSOAP_QT5_ONLY=${"${FLAVOR:Mqt6}" != "":?"@comment ":} \
		KDSOAP_QT6_SUFFIX=${"${FLAVOR:Mqt6}" != "":?-qt6:}

.include <bsd.port.mk>
