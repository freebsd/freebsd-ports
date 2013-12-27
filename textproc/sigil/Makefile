# Created by: Jonathan Chen <jonc@chen.org.nz>
# $FreeBSD$

PORTNAME=	sigil
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	Sigil-${PORTVERSION}-Code

MAINTAINER=	jonc@chen.org.nz
COMMENT=	WYSIWYG ePub editor

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libxerces-c.so:${PORTSDIR}/textproc/xerces-c3 \
		libhunspell-1.3.so:${PORTSDIR}/textproc/hunspell \
		libpcre.so:${PORTSDIR}/devel/pcre

LICENSE=	GPLv3

USE_ZIP=	yes
USES=		cmake pkgconfig
USE_DOS2UNIX=	CMakeLists.txt DirEnumerator.cpp ZipFile_stl.cpp ZipPlatform_lnx.cpp
NO_WRKSUBDIR=	yes
USE_QT4=	qmake gui svg webkit xml moc uic rcc imageformats linguist
USE_GNOME=	desktopfileutils

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/CMakeLists.txt

post-install:
	@-update-desktop-database > /dev/null

.include <bsd.port.mk>
