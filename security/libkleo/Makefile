PORTNAME=	libkleo
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library that provides cryptography support for mails
WWW=		https://invent.kde.org/pim/libkleo/

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs
LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libqgpgmeqt6.so:security/qgpgme@qt6 \
		libgpgmepp.so:security/gpgmepp
RUN_DEPENDS=	${LOCALBASE}/bin/gmd5sum:sysutils/coreutils

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	codecs colorscheme completion config coreaddons i18n \
		itemmodels widgetsaddons \
		ecm:build
USE_QT=		base

_CORETOOLS=	md5sum sha1sum sha256sum sha512sum

post-extract:
# use the binaries of coreutils
.  for ct in ${_CORETOOLS}
	${REINPLACE_CMD} -e '/create-command/ s#${ct}#g${ct}#' \
			 -e '/verify-command/ s#${ct}#g${ct}#' \
			 ${PATCH_WRKSRC}/src/libkleopatrarc.desktop
.  endfor

.include <bsd.port.mk>
