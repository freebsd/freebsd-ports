PORTNAME=	xprobe2
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/xprobe/xprobe2/Xprobe2%20${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ICMP active OS fingerprint scanner

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFIGURE_ENV=	INSTALL=${INSTALL}
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-DBROKEN_BSD||' ${WRKSRC}/libs-external/USI++/src/configure

.include <bsd.port.mk>
