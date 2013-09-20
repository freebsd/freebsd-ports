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

BUILD_DEPENDS=	v4l_compat>=1.0.20060801:${PORTSDIR}/multimedia/v4l_compat
LIB_DEPENDS=	libuclmmbase.so:${PORTSDIR}/devel/uclmmbase

USES=		gmake	# parallel builds (-jX) are broken with BSD make(1)
USE_AUTOTOOLS=	autoconf213
USE_TK=		84
USE_TK_BUILD=	84
USE_XORG=	xext
CONFIGURE_ARGS=	-x-libraries=${LOCALBASE}/lib \
		-x-includes=${LOCALBASE}/include \
		-without-ucltcl \
		-with-tcl=${LOCALBASE} \
		-without-ucltk \
		-with-tk=${LOCALBASE} \
		-enable-ipv6

MAN1=		vic.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,^main,int &,' ${WRKSRC}/tcl/tcl2cpp/tcl2cpp.c
	${RM} ${WRKSRC}/md5*

.include <bsd.port.mk>
