# Created by: Olivier Cochard-Labbe <olivier@cochard.me>
# $FreeBSD$

PORTNAME=	deforaos-browser
PORTVERSION=	0.4.13
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.defora.org/os/download/download/4310/
DISTNAME=	Browser-${PORTVERSION}

MAINTAINER=	olivier@cochard.me
COMMENT=	DeforaOS desktop file browser

LICENSE=	GPLv3

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
LIB_DEPENDS=	libSystem.so:${PORTSDIR}/devel/deforaos-libsystem \
		libDesktop.so:${PORTSDIR}/x11/deforaos-libdesktop \
		libXrandr.so:${PORTSDIR}/x11/libXrandr

USE_GNOME=	gtk20
USES=		desktop-file-utils gettext pkgconfig
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}

MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh

.include <bsd.port.mk>
