PORTNAME=	player
PORTVERSION=	0.2.0
CATEGORIES=	multimedia
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Player/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Player-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop media player
WWW=		https://www.defora.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libSystem.so:devel/deforaos-libsystem \
		libX11.so:x11/libX11
RUN_DEPENDS=	mpv:multimedia/mpv

USES=		desktop-file-utils gnome pkgconfig xorg
USE_GNOME=	gtk30
USE_XORG=	x11

MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${PREFIX}/share/man

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

post-install: compress-man
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/player \
		${STAGEDIR}${PREFIX}/bin/playerctl

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|data doc include|data include|' \
	${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|include po src|include src|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
