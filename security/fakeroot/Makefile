PORTNAME=	fakeroot
PORTVERSION=	2.1.4
CATEGORIES=	security
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Simulate the root user behaviour
WWW=		https://tracker.debian.org/pkg/fakeroot

LICENSE=	GPLv3

BUILD_DEPENDS=	po4a:textproc/po4a

USES=	libtool meson tar:xz

MESON_ARGS=		-Dipc=tcp
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libfakeroot-0.so \
		${STAGEDIR}${PREFIX}/lib/libfakeroot.so.0
	${LN} -sf libfakeroot.so.0 \
		${STAGEDIR}${PREFIX}/lib/libfakeroot-0.so

.include <bsd.port.mk>
