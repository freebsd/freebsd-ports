# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libde265
PORTVERSION=	1.0.2
PORTREVISION=	5
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Open source h.265 video codec

USE_GITHUB=	yes
GH_ACCOUNT=	strukturag

USES=		autoreconf compiler:c++11-lib libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-sherlock265 --disable-dec265

.include <bsd.port.pre.mk>

.if ${ARCH} == "armv6" || ${ARCH} == "armv7"
BUILD_DEPENDS+= ${LOCALBASE}/bin/as:devel/binutils
CONFIGURE_ENV+= CCASFLAGS="${CFLAGS} -B${LOCALBASE}/bin -no-integrated-as"
LLD_UNSAFE=     yes
.endif

.include <bsd.port.post.mk>
