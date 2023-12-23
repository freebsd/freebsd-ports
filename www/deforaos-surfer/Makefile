PORTNAME=	surfer
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Surfer/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Surfer-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop web browser
WWW=		https://www.defora.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3 \
		libharfbuzz.so:print/harfbuzz \
		libsoup-2.4.so:devel/libsoup

USES=		gnome desktop-file-utils pkgconfig gettext
USE_XORG=	x11
USE_GNOME=	gtk30 cairo gdkpixbuf2

MAKE_ARGS=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|= data doc|= data|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
