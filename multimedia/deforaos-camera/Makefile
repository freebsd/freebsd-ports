PORTNAME=	camera
PORTVERSION=	0.3.1
CATEGORIES=	multimedia
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Camera/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Camera-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop photo camera
WWW=		https://www.defora.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
LIB_DEPENDS=	libDesktop.so:x11/deforaos-libdesktop \
		libSystem.so:devel/deforaos-libsystem \
		libX11.so:x11/libX11
RUN_DEPENDS=	deforaos-browser:x11-fm/deforaos-browser

USES=		gnome pkgconfig xorg
USE_GNOME=	gtk30
USE_XORG=	x11

MAKE_ARGS+=	CPPFLAGS=-DPROGNAME_BROWSER=\\\"deforaos-browser\\\" \
		PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${PREFIX}/share/man

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|= data doc |= data |' \
	${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's| po src | src |' \
		${WRKSRC}/Makefile

post-install: compress-man
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/camera \
		${STAGEDIR}${PREFIX}/bin/gallery \
		${STAGEDIR}${PREFIX}/lib/Desktop/widget/camera.so

.include <bsd.port.mk>
