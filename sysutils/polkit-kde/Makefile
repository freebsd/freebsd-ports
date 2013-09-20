# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	polkit-kde
PORTVERSION=	0.99.1
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/apps/KDE4.x/admin/
DISTNAME=	${PORTNAME}-agent-1-${PORTVERSION:C/1$/0/}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Polkit authentication UI for KDE Workspaces

LICENSE=	GPLv2

LIB_DEPENDS=	polkit-qt-agent-1:${PORTSDIR}/sysutils/polkit-qt

USE_BZIP2=	yes
USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USES=		cmake

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DBUILD_po:BOOL=FALSE
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
