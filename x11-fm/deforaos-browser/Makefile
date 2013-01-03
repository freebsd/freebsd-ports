# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	deforaos-browser
PORTVERSION=	0.4.10
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.defora.org/os/download/download/4010/
DISTNAME=	Browser-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop file browser

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	System:${PORTSDIR}/devel/deforaos-libsystem \
		Desktop:${PORTSDIR}/x11/deforaos-libdesktop \
		Xrandr:${PORTSDIR}/x11/libXrandr

USE_GNOME=	gtk20 desktopfileutils
USE_PKGCONFIG=	build
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}

MAKE_ENV+=	MANDIR=${MANPREFIX}/man

MAN1=		browser.1 \
		copy.1 \
		delete.1 \
		desktop.1 \
		desktopctl.1 \
		move.1 \
		open.1 \
		properties.1 \
		view.1

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh

.include <bsd.port.mk>
