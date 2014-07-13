# Created by: lukin@okbmei.msk.su
# $FreeBSD$

PORTNAME=	asfiles
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	x11-fm afterstep windowmaker
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	apps/ASFiles
DISTNAME=	ASFiles-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 file manager. Dockable in WindowMaker

LIB_DEPENDS=	libDnd.so:${PORTSDIR}/x11/libdnd

USES=		perl5
GNU_CONFIGURE=	yes
USE_XORG=	xpm
USE_PERL5=	build
MAN1=	files.1
MAN3=	regexp.3

CONFIGURE_ARGS+=--with-dnd-inc=${LOCALBASE}/include \
		--with-dnd-lib=${LOCALBASE}/lib

NO_STAGE=	yes
post-install:
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/last-patch-aa
	${INSTALL_DATA} ${WRKSRC}/src/Files.ad ${PREFIX}/lib/X11/app-defaults/
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${MV} ${WRKSRC}/src/Files.ad.orig ${WRKSRC}/src/Files.ad

.include <bsd.port.mk>
