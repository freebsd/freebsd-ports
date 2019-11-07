# $FreeBSD$

PORTNAME=	luscus
DISTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	SF/${PORTNAME}/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Molecular editor and viewer

LICENSE=	AFL
LICENSE_NAME=	Academic Free License
LICENSE_FILE=	${WRKSRC}/License.txt
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgdkglext-x11-1.0.so:x11-toolkits/gtkglext
RUN_DEPENDS=	bash:shells/bash \
		babel:science/openbabel

USES=		cmake compiler:c++11-lang gettext-runtime gl gnome pkgconfig \
		shebangfix xorg
SHEBANG_GLOB=	*.sh
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 pango pangox-compat
USE_GL=		gl glu
USE_XORG=	x11

post-patch:
	@${REINPLACE_CMD} 's|/etc/luscus|${DATADIR}|' ${WRKSRC}/gv_system.c
	@${REINPLACE_CMD} -i '' 's|$$HOME/\.${PORTNAME}/|${LOCALBASE}/bin/|' ${WRKSRC}/*/*/*.sh
	@${REINPLACE_CMD} -i '' 's|$$RUNDIR/|${LOCALBASE}/bin/|' ${WRKSRC}/*/*/*.sh

.include <bsd.port.mk>
