# New ports collection makefile for:	fontconfig
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fontconfig
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.fontconfig.org/release/
DISTNAME=	fcpackage.${PORTVERSION:S/./_/}

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		expat.4:${PORTSDIR}/textproc/expat2
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-confdir=${PREFIX}/etc/fonts \
		--with-expat=${LOCALBASE} \
		--with-default-fonts=${X11BASE}/lib/X11/fonts
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
WRKSRC=	${WRKDIR}/${DISTNAME}/fontconfig

pre-patch:
	@${REINPLACE_CMD} -e 's|[(]LIBDIR[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
