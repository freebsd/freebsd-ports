# Created by: arved
# $FreeBSD$

PORTNAME=	telepathy-qt
PORTVERSION=	0.14.1
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	SF/tapioca-voip/${PORTNAME}/${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Framework for VoIP and IP applications

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../COPYING

DEPRECATED=	Unmaintained upstream since 2007, use net-im/telepathy-qt4
EXPIRATION_DATE=	2013-12-01

USES=		cmake pkgconfig
CMAKE_SOURCE_PATH=	..
USE_QT4=	corelib qmake_build uic_build moc_build rcc_build xml dbus
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/build

NO_STAGE=	yes
post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		"s,$${LIB_INSTALL_DIR}/pkgconfig,data/pkgconfig,g"\
		${WRKSRC}/../CMakeLists.txt

.include <bsd.port.mk>
