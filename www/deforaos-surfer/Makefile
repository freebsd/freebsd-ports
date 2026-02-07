PORTNAME=	surfer
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Surfer/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Surfer-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop web browser
WWW=		https://www.defora.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libharfbuzz.so:print/harfbuzz \
		libsoup-2.4.so:devel/libsoup \
		libSystem.so:devel/deforaos-libsystem \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40

USES=		desktop-file-utils gnome pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf gtk30
USE_XORG=	x11

MAKE_ARGS=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${PREFIX}/share/man

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_SUB=		yes
DOCS_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			xsltproc:textproc/libxslt

NLS_USES=		gettext

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|= data doc|= data|' \
		${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|data po src|data src|' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
