# New ports collection makefile for:	Xft
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Xft
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	http://fontconfig.org/release/
DISTNAME=	fcpackage.${PORTVERSION:S/./_/}

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LIBS="-L${X11BASE}/lib"
WRKSRC=	${WRKDIR}/${DISTNAME}/Xft

.include <bsd.port.pre.mk>

# TODO Add a check to make sure we're not using XFree86 4.3.x which will
# have Xft2 included by default.
.if ${XFREE86_VERSION} == 3
BROKEN=	Xft2 requires XFree86 4.x to build.
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|[(]LIBDIR[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
