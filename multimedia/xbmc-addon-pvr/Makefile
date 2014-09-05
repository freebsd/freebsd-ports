# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xbmc-pvr-addons
PORTVERSION=	12.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://people.freebsd.org/~decke/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-20140104

MAINTAINER=	decke@FreeBSD.org
COMMENT=	XBMC PVR addons for various backends

BUILD_DEPENDS+=	xbmc:${PORTSDIR}/multimedia/xbmc
RUN_DEPENDS+=	xbmc:${PORTSDIR}/multimedia/xbmc

USE_GITHUB=	yes
GH_ACCOUNT=	opdenkamp
GH_COMMIT=	9021115
GH_TAGNAME=	9021115

USES=		libtool pkgconfig
USE_GL=		gl
USE_AUTOTOOLS=	libtoolize aclocal automake autoconf
MAKE_JOBS_SAFE=	yes
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
REINPLACE_ARGS=	-i ''

CFLAGS+=	"-I${LOCALBASE}/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

post-patch:
	# addons for FreeBSD look for linux platform
	@${REINPLACE_CMD} 's|@OS@|freebsd linux|' \
		${WRKSRC}/addons/*/addon/addon.xml.in
	@${REINPLACE_CMD} 's|-ldl||' \
		${WRKSRC}/addons/pvr.hts/Makefile.am
	@${RM} ${WRKSRC}/addons/*/addon/addon.xml.in.orig

.include <bsd.port.post.mk>
