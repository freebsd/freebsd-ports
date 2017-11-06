# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	fakeroot
PORTVERSION=	1.22
CATEGORIES=	security
MASTER_SITES=	DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Simulate the root user behaviour

LICENSE=	GPLv3

USES=	tar:bzip2 libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=		--with-ipc=tcp
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/lib/libfakeroot-0.so \
		${STAGEDIR}${PREFIX}/lib/libfakeroot.so.0
	${LN} -sf libfakeroot.so.0 \
		${STAGEDIR}${PREFIX}/lib/libfakeroot-0.so

.include <bsd.port.mk>
