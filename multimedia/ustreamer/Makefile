PORTNAME=	ustreamer
DISTVERSIONPREFIX=	v
DISTVERSION=	3.27
CATEGORIES=	multimedia net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and fast MJPG-HTTP streamer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat
LIB_DEPENDS=	libevent.so:devel/libevent \
		libuuid.so:misc/e2fsprogs-libuuid

USES=		compiler:c11 gmake jpeg localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	pikvm

MAKE_ARGS=	WITH_PTHREAD_NP=0

INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/ustreamer \
		bin/ustreamer-dump \
		man1/ustreamer-dump.1.gz \
		man1/ustreamer.1.gz

.include <bsd.port.options.mk>

# strerror_l appeared in 12 in r368915 on 2021-01-01, OSVERSION was last changed to 1202505 in r368887 on 2020-12-29
post-patch:
.if ${OPSYS} == "FreeBSD" && ${OSVERSION} <= 1202505
	@${REINPLACE_CMD} -e 's|strerror_l(error, locale)|strerror(error)|' ${WRKSRC}/src/libs/tools.h
.endif

.include <bsd.port.mk>
