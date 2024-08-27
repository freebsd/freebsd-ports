PORTNAME=	pass-secrets
PORTVERSION=	s20240404
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freedesktop secrets provider that uses pass as a backend
WWW=		https://github.com/nullobsi/pass-secrets

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsdbus-c++.so:devel/sdbus-cpp
RUN_DEPENDS=	pass:sysutils/password-store

USES=		cmake compiler:c++17-lang
USE_GITHUB=	yes
GH_ACCOUNT=	nullobsi
GH_TAGNAME=	e313297
PLIST_FILES=	bin/${PORTNAME} \
		share/dbus-1/services/si.nullob.pass-secrets.service

post-patch:
	@${REINPLACE_CMD} '/systemd/d' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
