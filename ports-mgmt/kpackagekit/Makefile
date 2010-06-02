# New ports collection makefile for:	kpackagekit
# Date created:				11 May 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	KPackageKit
PORTVERSION=	0.6.0
CATEGORIES=	ports-mgmt sysutils kde
MASTER_SITES=	http://kde-apps.org/CONTENT/content-files/
DISTNAME=	84745-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.7z

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE interface for PackageKit

EXTRACT_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip
LIB_DEPENDS=	packagekit-qt.14:${PORTSDIR}/ports-mgmt/packagekit-qt4

EXTRACT_CMD=	7z x
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	> /dev/null
USE_GETTEXT=	yes
USE_GNOME=	pkgconfig
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

pre-install:
	${REINPLACE_CMD} -e 's/$${_install_dir}/$${DBUS_SERVICES_INSTALL_DIR}/' \
		${WRKSRC}/cmake/modules/PkgConfigGetVar.cmake

.include <bsd.port.mk>
