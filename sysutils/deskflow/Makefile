PORTNAME=	deskflow
DISTVERSIONPREFIX=	v
DISTVERSION=	1.24.0
CATEGORIES=	sysutils

PATCH_SITES=	https://github.com/deskflow/deskflow/commit/

MAINTAINER=	ykasap@gmail.com
COMMENT=	Mouse and keyboard sharing utility
WWW=		https://deskflow.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	requires OpenSSL 3.0

BUILD_DEPENDS=	${LOCALBASE}/include/CLI/Version.hpp:devel/cli11 \
		googletest>0:devel/googletest \
		help2man:misc/help2man
LIB_DEPENDS=	libei.so:x11/libei \
		libportal.so:deskutils/libportal \
		libtomlplusplus.so:devel/tomlplusplus \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++20-lang gl gnome pkgconfig qt:6 ssl xorg
USE_GITHUB=	yes
USE_GL=		opengl
USE_GNOME=	glib20
USE_QT=		base
USE_XORG=	ice sm x11 xext xi xinerama xkbfile xrandr xtst

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CMAKE_BOOL=	BUILD_DOCS

post-patch:
# Hardcoded paths need to be replaced
	@${REINPLACE_CMD} -e 's|/usr/local/share/X11/xkb|${PREFIX}/share/X11/xkb|' \
		${WRKSRC}/src/lib/deskflow/unix/AppUtilUnix.cpp
	@${REINPLACE_CMD} -e 's|/etc/|${PREFIX}/etc/|' \
		${WRKSRC}/src/lib/common/Settings.h

do-test:
	@(cd ${BUILD_WRKSRC} && \
	${SETENVI} ${WRK_ENV} ${TEST_ENV} ${BUILD_WRKSRC}/bin/legacytests)

.include <bsd.port.mk>
