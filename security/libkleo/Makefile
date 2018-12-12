# $FreeBSD$

PORTNAME=	libkleo
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	security kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Certificate manager for KDE

LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libqgpgme.so:security/gpgme-qt5 \
		libgpgmepp.so:security/gpgme-cpp
RUN_DEPENDS=	${LOCALBASE}/bin/gmd5sum:sysutils/coreutils


USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	codecs completion config coreaddons i18n itemmodels \
		widgetsaddons windowsystem \
		pimtextedit
USE_QT=		core gui widgets \
		buildtools_build qmake_build

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
