# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	pdfviewer
PORTVERSION=	0.0.1
CATEGORIES=	print
MASTER_SITES=	http://www.defora.org/os/download/download/3686/
DISTNAME=	PDFViewer-${PORTVERSION}
PKGNAMEPREFIX=	deforaos-

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop PDF viewer

LICENSE=	GPLv3

LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop \
		poppler-glib:${PORTSDIR}/graphics/poppler-glib

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
PLIST_FILES=	bin/pdfviewer \
		share/applications/pdfviewer.desktop

.include <bsd.port.mk>
