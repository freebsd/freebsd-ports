# Ports collection makefile for: libv4l
# Date created: 13 January 2010
# Whom:         Andrew Thompson <thompsa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libv4l
PORTVERSION=	0.6.3
CATEGORIES=	multimedia
MASTER_SITES=	http://people.fedoraproject.org/~jwrdegoede/

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Video4Linux library

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat

MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" LIBDIR="${PREFIX}/lib"
USE_GZIP=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|$$(LIBDIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/libv4l1/Makefile \
		${WRKSRC}/libv4l2/Makefile \
		${WRKSRC}/libv4lconvert/Makefile

.include <bsd.port.post.mk>
