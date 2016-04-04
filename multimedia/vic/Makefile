# Created by: Garrett Wollman <wollman@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vic
PORTVERSION=	2.8.1.1.6
PORTREVISION=	2
CATEGORIES=	multimedia tk ipv6
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/vic/2.8ucl1.1.6/
DISTNAME=	${PORTNAME}-2.8ucl1.1.6

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	MBone video conferencing tool

BUILD_DEPENDS=	v4l_compat>=1.0.20060801:multimedia/v4l_compat
LIB_DEPENDS=	libuclmmbase.so:devel/uclmmbase

USES=		autoreconf gmake tk:84 # parallel builds (-jX) are broken with BSD make(1)
USE_OPENSSL=	yes
USE_XORG=	xext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	-x-libraries=${LOCALBASE}/lib \
		-x-includes=${LOCALBASE}/include \
		-without-ucltcl \
		-with-tcl=${LOCALBASE} \
		-without-ucltk \
		-with-tk=${LOCALBASE} \
		-enable-ipv6
MAKE_ENV+=	STAGEDIR=${STAGEDIR}

post-patch:
	@${REINPLACE_CMD} -e 's,^main,int &,' ${WRKSRC}/tcl/tcl2cpp/tcl2cpp.c
	${RM} ${WRKSRC}/md5*

.include <bsd.port.mk>
