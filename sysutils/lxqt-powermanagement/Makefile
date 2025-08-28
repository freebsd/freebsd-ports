PORTNAME=	lxqt-powermanagement
PORTVERSION=	2.2.0
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	LXQt power management
WWW=		https://github.com/lxqt/lxqt-powermanagement

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	upower:sysutils/upower

USES=		cmake compiler:c++20-lang gettext-runtime kde:6 lxqt:2 qt:6 \
		localbase:ldflags perl5 pkgconfig tar:xz gnome xorg
USE_PERL5=	build
USE_QT=		base:run tools:build svg
USE_GNOME=	glib20
USE_KDE=	idletime solid windowsystem
USE_LXQT=	buildtools2 lxqt globalkeys
USE_XORG=	x11
.include <bsd.port.mk>
