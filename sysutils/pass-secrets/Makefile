PORTNAME=	pass-secrets
PORTVERSION=	s20211221
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Freedesktop secrets provider that uses pass as a backend

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsdbus-c++.so:devel/sdbus-cpp
RUN_DEPENDS=	pass:sysutils/password-store

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	nullobsi
GH_TAGNAME=	e91a1b3
CMAKE_OFF=	INSTALL_DBUS_SERVICE
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} '/systemd/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
