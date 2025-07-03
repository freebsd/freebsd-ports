PORTNAME=	hyprland-qt-support
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	x11-toolkits

MAINTAINER=	ports@FreeBSD.org
COMMENT=	QML style provider for hypr* Qt apps
WWW=		https://github.com/hyprwm/hyprland-qt-support

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libhyprlang.so:devel/hyprlang

USES=		cmake compiler:c++11-lib localbase:ldflags pkgconfig qt:6
USE_GITHUB=	yes
USE_QT=		base declarative
GH_ACCOUNT=	hyprwm
LDFLAGS+=	-Wl,--as-needed # Qt deps
CMAKE_ARGS=	-DINSTALL_QML_PREFIX:PATH="${QT_QMLDIR_REL}"

post-patch:
# Respect PREFIX for system-wide config
	@${REINPLACE_CMD} 's,/etc,${PREFIX}&,' \
		${WRKSRC}/src/style/impl/hyprlandstyle.cpp

.include <bsd.port.mk>
