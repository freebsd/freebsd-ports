# Created by: Raphael Kubo da Costa <rakuco@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nepomuk-core
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	21
CATEGORIES=	sysutils kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Core Nepomuk system libraries and services for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libtag.so:audio/taglib \
		libexiv2.so:graphics/exiv2 \
		libswscale.so:multimedia/ffmpeg \
		libepub.so:textproc/ebook-tools \
		libqmobipocket.so:graphics/kdegraphics-mobipocket-kde4

USES=		cmake kde:4 python:run qt:4 shebangfix tar:xz
USE_KDE=	automoc4 baloo kdelibs kfilemetadata \
		ontologies soprano
USE_QT=		corelib dbus gui qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

SHEBANG_FILES=	services/storage/rcgen/nepomuk-simpleresource-rcgen.py

SUB_FILES=	nepomuk-env.sh

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/nepomuk-env.sh ${STAGEDIR}${PREFIX}/env

.include <bsd.port.mk>
