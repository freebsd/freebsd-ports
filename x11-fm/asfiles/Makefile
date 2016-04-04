# Created by: lukin@okbmei.msk.su
# $FreeBSD$

PORTNAME=	asfiles
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	x11-fm afterstep windowmaker
MASTER_SITES=	AFTERSTEP/apps/ASFiles
DISTNAME=	ASFiles-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 file manager. Dockable in WindowMaker

LIB_DEPENDS=	libDnd.so:x11/libdnd

USES=		perl5
GNU_CONFIGURE=	yes
USE_XORG=	xpm
USE_PERL5=	build

CONFIGURE_ARGS+=--with-dnd-inc=${LOCALBASE}/include \
		--with-dnd-lib=${LOCALBASE}/lib

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|g' \
		${WRKSRC}/src/Files.ad

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/Files.ad ${STAGEDIR}${PREFIX}/lib/X11/app-defaults/

.include <bsd.port.mk>
