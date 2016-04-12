# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pdfviewer
PORTVERSION=	0.0.1
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	http://www.defora.org/os/download/download/3686/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	PDFViewer-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop PDF viewer

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libpoppler-glib.so:graphics/poppler-glib

MAKE_ARGS+=	PREFIX=${PREFIX}
USES=		desktop-file-utils pkgconfig
USE_GNOME=	gtk20
PLIST_FILES=	bin/pdfviewer \
		share/applications/pdfviewer.desktop

.include <bsd.port.mk>
