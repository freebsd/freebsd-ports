# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	pulseview
PORTVERSION=	0.4.1
PORTREVISION=	7
CATEGORIES=	science cad
MASTER_SITES=	http://sigrok.org/download/source/pulseview/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	GUI client that supports various hardware logic analyzers

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libsigrok.so:devel/libsigrok \
		libsigrokdecode.so:devel/libsigrokdecode

USES=		cmake compiler:c++14-lang desktop-file-utils gnome pkgconfig qt:5
USE_GNOME=	glibmm glib20 libsigc++20
USE_QT=		buildtools core gui qmake_build svg widgets

CMAKE_ARGS+=	-DCMAKE_INSTALL_MANDIR:PATH=${MANPREFIX}/man \
		-DDISABLE_WERROR:BOOL=TRUE
INSTALLS_ICONS=	yes

PLIST_FILES=	bin/pulseview man/man1/pulseview.1.gz \
		share/applications/org.sigrok.PulseView.desktop \
		share/icons/hicolor/48x48/apps/pulseview.png \
		share/icons/hicolor/scalable/apps/pulseview.svg \
		share/metainfo/org.sigrok.PulseView.appdata.xml

MAKE_JOBS_UNSAFE=yes

.include <bsd.port.mk>
