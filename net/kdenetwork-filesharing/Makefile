PORTNAME=	kdenetwork-filesharing
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Filesharing via Samba

BUILD_DEPENDS=	${LOCALBASE}/include/qcoro5/qcoro/qcoro.h:devel/qcoro@qt5

USES=		cmake compiler:c++11-lang gettext-tools kde:5 qt:5 tar:xz xorg
USE_KDE=	auth completion config coreaddons doctools i18n jobwidgets \
		kio service solid widgetsaddons windowsystem \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network widgets \
		buildtools:build qmake:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} && ${OSVERSION} < 1400092
CXX=		clang++${LLVM_VERSION}
USES+=		llvm:min=16
.endif

.include <bsd.port.mk>
