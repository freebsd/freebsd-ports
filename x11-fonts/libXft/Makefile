# New ports collection makefile for:	Xft
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Xft
PORTVERSION=	2.1
PORTREVISION=	8
CATEGORIES=	x11-fonts
MASTER_SITES=	http://fontconfig.org/fontconfig/release/
DISTNAME=	fcpackage.${PORTVERSION:S/./_/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A client-sided font API for X applications

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-fontconfig-config="pkg-config fontconfig"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"
WRKSRC=	${WRKDIR}/${DISTNAME}/Xft

MAN3=		Xft.3

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
BROKEN=	Xft2 requires XFree86 4.x to build.
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|[(]LIBDIR[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

pre-install:
	-${MKDIR} ${PREFIX}/include/X11/Xft

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Xft.man ${PREFIX}/man/man3/Xft.3

.include <bsd.port.post.mk>
