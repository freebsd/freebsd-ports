# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	radeontop
PORTVERSION=	1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Program that shows AMD Radeon GPU resource utilization

LICENSE=	GPLv3

LIB_DEPENDS=	libpciaccess.so:devel/libpciaccess \
		libdrm.so:graphics/libdrm

NOT_FOR_ARCHS=		aarch64 armv6 armv7 mips mips64
NOT_FOR_ARCHS_REASON=	fails to compile: fatal error: amdgpu_drm.h file not found

USE_GITHUB=	yes
GH_ACCOUNT=	clbr

USES=		gmake pkgconfig xorg
USE_XORG=	xcb
MAKE_ARGS=	amdgpu=1

PLIST_FILES=	lib/libradeontop_xcb.so \
		man/man1/radeontop.1.gz \
		sbin/radeontop

OPTIONS_DEFINE=	NLS

NLS_USES=		gettext
NLS_MAKE_ARGS_OFF=	nls=0
NLS_PLIST_FILES=	share/locale/ru/LC_MESSAGES/radeontop.mo

post-patch:
	@${REINPLACE_CMD} -e 's,unknown,v${PORTVERSION}, ; \
		s,-n,"$$ver" = unknown -a &,' ${WRKSRC}/getver.sh
	@${REINPLACE_CMD} -e 's,/usr,${PREFIX},' ${WRKSRC}/radeontop.c
# cdevs do not provide private mappings of any kind
	@${REINPLACE_CMD} -e 's,MAP_PRIVATE,MAP_SHARED,' \
		${WRKSRC}/detect.c

.include <bsd.port.mk>
