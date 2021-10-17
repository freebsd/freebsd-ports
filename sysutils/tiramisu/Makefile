PORTNAME=	tiramisu
DISTVERSION=	2.0
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	964ea74c9889.patch:-p1 # https://github.com/Sweets/tiramisu/pull/35
PATCHFILES+=	1c3d3e64cffb.patch:-p1 # https://github.com/Sweets/tiramisu/pull/35

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Desktop notifications, the UNIX way

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	valac:lang/vala

USES=		gmake gnome pkgconfig
USE_GITHUB=	yes
USE_GNOME=	glib20
GH_ACCOUNT=	Sweets
PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
