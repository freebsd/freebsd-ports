PORTNAME=	pulseview
PORTVERSION=	0.4.2
PORTREVISION=	8
CATEGORIES=	science cad
MASTER_SITES=	http://sigrok.org/download/source/pulseview/

# Fix build with glib 2.68.3
PATCH_SITES=	https://github.com/sigrokproject/pulseview/commit/
PATCHFILES=	ed643f0b4ac587204a5243451cda181ee1405d62.diff:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI client that supports various hardware logic analyzers
WWW=		https://sigrok.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libsigrok.so:devel/libsigrok \
		libsigrokdecode.so:devel/libsigrokdecode

USES=		cmake compiler:c++14-lang desktop-file-utils gnome pkgconfig qt:5
USE_GNOME=	glibmm glib20 libsigc++20
USE_QT=		buildtools:build core gui linguisttools:build qmake:build svg widgets

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${PREFIX}/share/man \
		-DDISABLE_WERROR:BOOL=TRUE

PLIST_FILES=	bin/pulseview share/man/man1/pulseview.1.gz \
		share/applications/org.sigrok.PulseView.desktop \
		share/icons/hicolor/48x48/apps/pulseview.png \
		share/icons/hicolor/scalable/apps/pulseview.svg \
		share/metainfo/org.sigrok.PulseView.appdata.xml

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
