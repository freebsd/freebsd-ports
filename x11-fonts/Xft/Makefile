# New ports collection makefile for:	Xft
# Date created:		06 October 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Xft
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://fontconfig.org/fontconfig/release/
DISTNAME=	fcpackage.${PORTVERSION:S/./_/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A client-sided font API for X applications

LIB_DEPENDS=	fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	${FONTSCALE}:${PORTSDIR}/x11-fonts/XFree86-4-fontScalable \
		${FONTENCOD}:${PORTSDIR}/x11-fonts/XFree86-4-fontEncodings

FONTSCALE=	${X11BASE}/lib/X11/fonts/TTF/luximb.ttf
FONTENCOD=	${X11BASE}/lib/X11/fonts/encodings/tcvn-0.enc

USE_GMAKE=	yes
USE_X_PREFIX=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
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
	@${SED} -e 's|%%X11BASE%%|${X11BASE}|' < ${FILESDIR}/pkg-install.in \
		> ${PKGINSTALL}
.if !defined(PACKAGE_BUILDING)
	 @${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
