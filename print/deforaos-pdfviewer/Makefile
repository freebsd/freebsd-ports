# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	pdfviewer
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.defora.org/os/download/download/3686/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	PDFViewer-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop PDF viewer

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:${PORTSDIR}/devel/deforaos-libsystem \
		libDesktop.so:${PORTSDIR}/x11/deforaos-libdesktop \
		libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib

MAKE_ARGS+=	PREFIX=${PREFIX}
USES=		desktop-file-utils pkgconfig
USE_GNOME=	gtk20
PLIST_FILES=	bin/pdfviewer \
		share/applications/pdfviewer.desktop

.include <bsd.port.mk>
