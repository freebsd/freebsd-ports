PORTNAME=	girara
DISTVERSION=	2026.02.04
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	https://pwmt.org/projects/girara/download/

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Common components for Zathura PDF Viewer
WWW=		https://pwmt.org/projects/girara/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c17 gnome meson pkgconfig tar:xz
USE_GNOME=	glib20
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocs=disabled \
		-Dtests=disabled

.include <bsd.port.mk>
