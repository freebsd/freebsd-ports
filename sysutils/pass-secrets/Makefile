PORTNAME=	pass-secrets
PORTVERSION=	s20220122
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
GH_TAGNAME=	1b7a323
CMAKE_OFF=	INSTALL_DBUS_SERVICE
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} '/systemd/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
