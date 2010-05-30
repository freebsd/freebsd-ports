# New ports collection Makefile for:		tapioca-qt
# Date created:					2008-02-10
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	tapioca-qt
PORTVERSION=	0.14.1
PORTREVISION=	5
CATEGORIES=	net-im
MASTER_SITES=	SF/tapioca-voip/${PORTNAME}/${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Framework for VoIP and IP applications

LIB_DEPENDS=	QtTelepathyCore.0:${PORTSDIR}/net-im/telepathy-qt

LICENSE=	LGPL
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/build

USE_CMAKE=	yes
CMAKE_SOURCE_PATH=	..
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build uic_build moc_build rcc_build
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700042
CMAKE_USE_PTHREAD=	yes
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		"s,$${LIB_INSTALL_DIR}/pkgconfig,data/pkgconfig,g"\
		${WRKSRC}/../CMakeLists.txt

.include <bsd.port.post.mk>
