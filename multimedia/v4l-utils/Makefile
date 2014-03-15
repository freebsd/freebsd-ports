# Created by: Juergen Lock <nox@FreeBSD.org>
# $FreeBSD$

PORTNAME=	v4l-utils
PORTVERSION=	0.8.8
CATEGORIES=	multimedia
MASTER_SITES=	http://linuxtv.org/downloads/v4l-utils/

MAINTAINER=	nox@FreeBSD.org
COMMENT=	Video4Linux utilities

BUILD_DEPENDS=	v4l_compat>=1.0.20120501:${PORTSDIR}/multimedia/v4l_compat \
		libv4l>=0.8.8:${PORTSDIR}/multimedia/libv4l
LIB_DEPENDS=	v4l2.0:${PORTSDIR}/multimedia/libv4l \
		argp.0:${PORTSDIR}/devel/argp-standalone

MAKE_ARGS=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -DPREFIX=\\\"${PREFIX}\\\"" \
		LIBDIR="${PREFIX}/lib" LDFLAGS="-L${LOCALBASE}/lib -largp"
USES=		gmake tar:bzip2
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/utils

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
EXTRA_PATCHES=	${FILESDIR}/extra-strnlen
.endif

post-patch:
	@${RM} ${WRKSRC}/../include/linux/videodev2.h
	@${REINPLACE_CMD} -e 's|#include <sys/klog.h>||g' \
		-e 's|#include <features.h>||g' \
		-e 's|#include <linux/types.h>||g' \
		${WRKSRC}/v4l2-compliance/v4l2-compliance.cpp \
		${WRKSRC}/v4l2-compliance/v4l2-test-debug.cpp \
		${WRKSRC}/v4l2-ctl/cx18-ctl.c \
		${WRKSRC}/v4l2-ctl/ivtv-ctl.c \
		${WRKSRC}/../include/linux/ivtv.h

.include <bsd.port.post.mk>
