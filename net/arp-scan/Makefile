PORTNAME=	arp-scan
PORTVERSION=	1.10.0
CATEGORIES=	net

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	ARP scanning and fingerprinting tool
WWW=		https://github.com/royhills/arp-scan

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	royhills

x-post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/get-iab

.include <bsd.port.mk>
