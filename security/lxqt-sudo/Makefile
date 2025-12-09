PORTNAME=	lxqt-sudo
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	LXQT

MAINTAINER=	lxqt@FreeBSD.org
COMMENT=	GUI frontend to su/sudo/doas for LXQt desktop
WWW=		https://lxqt-project.org

LICENSE=	LGPL21+

USES=		cmake compiler:c++20-lang gettext kde:6 lxqt:2 qt:6 perl5 tar:xz \
		gnome sudo xorg
USE_PERL5=	build
USE_QT=		base:run tools:build svg

USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools2 lxqt
USE_XORG=	x11

.include <bsd.port.mk>
