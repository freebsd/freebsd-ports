# $FreeBSD$

PORTNAME=	libkleo
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Certificate manager for KDE

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libqgpgme.so:security/gpgme-qt5 \
		libgpgmepp.so:security/gpgme-cpp
RUN_DEPENDS=	${LOCALBASE}/bin/gmd5sum:sysutils/coreutils


USES=		cmake:outsource gettext kde:5 tar:xz
USE_KDE=	codecs completion config coreaddons i18n itemmodels \
		widgetsaddons windowsystem \
		pimtextedit
USE_QT5=	core gui widgets \
		buildtools_build qmake_build

post-extract:
# use the binaries of coreutils
	${REINPLACE_CMD} -e '/create-command/ s#sha1sum#gsha1sum#' \
			 -e '/create-command/ s#md5sum#gmd5sum#' \
			 -e '/verify-command/ s#sha1sum#gsha1sum#' \
			 -e '/verify-command/ s#md5sum#gmd5sum#' \
		${PATCH_WRKSRC}/src/libkleopatrarc.desktop

.include <bsd.port.mk>
