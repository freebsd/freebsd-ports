PORTNAME=	kdenetwork-filesharing
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Filesharing via Samba

LIB_DEPENDS=	libQCoro6Core.so:devel/qcoro

USES=		cmake compiler:c++20-lang gettext-tools kde:6 qt:6 tar:xz xorg
USE_KDE=	auth completion config coreaddons doctools i18n jobwidgets kio \
		service solid widgetsaddons windowsystem \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc*} && ${OSVERSION} < 1400092
CXX=		clang++${LLVM_VERSION}
USES+=		llvm:min=16
.endif

.include <bsd.port.mk>
