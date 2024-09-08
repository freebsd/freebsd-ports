PORTNAME=	tiramisu
DISTVERSION=	2.0.20240610
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop notifications, the UNIX way
WWW=		https://github.com/Sweets/tiramisu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gnome pkgconfig vala:build
USE_GITHUB=	yes
USE_GNOME=	glib20
GH_ACCOUNT=	Sweets
MAKE_ARGS=	CC="${CC} ${CFLAGS}"
PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
