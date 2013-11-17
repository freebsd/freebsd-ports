# Created by: arved
# $FreeBSD$

PORTNAME=	tapioca-qt
PORTVERSION=	0.14.1
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	SF/tapioca-voip/${PORTNAME}/${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Framework for VoIP and IP applications

LIB_DEPENDS=	QtTelepathyCore.0:${PORTSDIR}/net-im/telepathy-qt

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../COPYING

DEPRECATED=	Unmaintained upstream since 2007, not used by anything
EXPIRATION_DATE=	2013-12-01

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/build

USES=		cmake pkgconfig
CMAKE_SOURCE_PATH=	..
USE_QT4=	corelib qmake_build uic_build moc_build rcc_build
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		"s,$${LIB_INSTALL_DIR}/pkgconfig,data/pkgconfig,g"\
		${WRKSRC}/../CMakeLists.txt

.include <bsd.port.post.mk>
