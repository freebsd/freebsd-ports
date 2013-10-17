# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	schroedinger
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://diracvideo.org/download/schroedinger/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-speed Dirac codec

LICENSE=	GPLv2 LGPL20 MIT MPL
LICENSE_COMB=	dual
LICENSE_FILE_MIT=	${WRKSRC}/COPYING.MIT
LICENSE_FILE_MPL=	${WRKSRC}/COPYING.MPL

LIB_DEPENDS=	liborc-0.4.so:${PORTSDIR}/devel/orc

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^pkgconfigdir=.*|pkgconfigdir="\\$${prefix}/libdata/pkgconfig"|' \
		-e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
