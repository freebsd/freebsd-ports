# New ports collection Makefile for:	decibel
# Date created:				2008-02-10
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	decibel
PORTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	net-im
MASTER_SITES=	http://decibel.kde.org/fileadmin/downloads/decibel/releases/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Realtime communications framework

LIB_DEPENDS=	QtTapioca.0:${PORTSDIR}/net-im/tapioca-qt

USE_QT_VER=	4
QT_COMPONENTS=	corelib xml dbus moc_build uic_build rcc_build qtestlib
USE_LDCONFIG=	yes
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/build
CMAKE_SOURCE_PATH=	.. 

.include <bsd.port.pre.mk>

.if (${ARCH} == amd64) && (${OSVERSION} < 600000)
BROKEN=		Does not compile
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e \
		"s,$${LIB_INSTALL_DIR}/pkgconfig,data/pkgconfig,g"\
		${WRKSRC}/../src/client/Decibel/CMakeLists.txt

.include <bsd.port.post.mk>
