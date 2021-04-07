PORTNAME=	tiramisu
DISTVERSION=	1.0
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Desktop notifications, the UNIX way

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake gnome pkgconfig
USE_GITHUB=	yes
USE_GNOME=	glib20
GH_ACCOUNT=	Sweets
PLIST_FILES=	bin/${PORTNAME}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
