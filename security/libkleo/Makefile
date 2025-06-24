PORTNAME=	libkleo
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Certificate manager for KDE
WWW=		https://www.kde.org/applications/utilities/kleopatra/

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libqgpgmeqt6.so:security/qgpgme@qt6 \
		libgpgmepp.so:security/gpgmepp
RUN_DEPENDS=	${LOCALBASE}/bin/gmd5sum:sysutils/coreutils

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		itemmodels pimtextedit widgetsaddons windowsystem \
		ecm:build
USE_QT=		base

_CORETOOLS=	md5sum sha1sum sha256sum sha512sum

OPTIONS_DEFINE=	DOCS

post-extract:
# use the binaries of coreutils
.  for ct in ${_CORETOOLS}
	${REINPLACE_CMD} -e '/create-command/ s#${ct}#g${ct}#' \
			 -e '/verify-command/ s#${ct}#g${ct}#' \
			 ${PATCH_WRKSRC}/src/libkleopatrarc.desktop
.  endfor

.include <bsd.port.mk>
