PORTNAME=	pass-secrets
PORTVERSION=	s20210930
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	1381a097ef34.patch:-p1 # https://github.com/nullobsi/pass-secrets/pull/3
PATCHFILES+=	01cc706f52c8.patch:-p1 # https://github.com/nullobsi/pass-secrets/pull/3

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Freedesktop secrets provider that uses pass as a backend

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsdbus-c++.so:devel/sdbus-cpp
RUN_DEPENDS=	pass:sysutils/password-store

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	nullobsi
GH_TAGNAME=	cee6b85
CMAKE_OFF=	INSTALL_DBUS_SERVICE
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
