# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	polkit-kde
PORTVERSION=	0.99.1
PORTREVISION=	3
CATEGORIES=	sysutils kde
MASTER_SITES=	KDE/stable/apps/KDE4.x/admin/
DISTNAME=	${PORTNAME}-agent-1-${PORTVERSION:C/1$/0/}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Polkit authentication UI for KDE Workspaces

LICENSE=	GPLv2

LIB_DEPENDS=	libpolkit-qt-agent-1.so:sysutils/polkit-qt

USE_KDE4=	kdelibs automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USES=		cmake tar:bzip2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CMAKE_OFF=	-DBUILD_po:BOOL=FALSE
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
