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

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs \
		xerces-c:${PORTSDIR}/textproc/xerces-c3 \
		hunspell-1.3:${PORTSDIR}/textproc/hunspell \
		pcre:${PORTSDIR}/devel/pcre

LICENCE=	GPLv3

USE_ZIP=	yes
USE_CMAKE=	yes
USE_DOS2UNIX=	CMakeLists.txt DirEnumerator.cpp ZipFile_stl.cpp ZipPlatform_lnx.cpp
NO_WRKSUBDIR=	yes
USE_QT4=	qmake gui svg webkit xml moc uic rcc imageformats linguist
USE_GNOME=	desktopfileutils
USE_PKGCONFIG=	build

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/CMakeLists.txt

post-install:
	@-update-desktop-database > /dev/null

.include <bsd.port.mk>
