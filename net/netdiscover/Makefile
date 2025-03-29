PORTNAME=	netdiscover
DISTVERSION=	0.11
MASTER_SITES=	https://github.com/netdiscover-scanner/netdiscover/releases/download/${DISTVERSION}/
CATEGORIES=	net

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Network address discovering tool
WWW=		https://github.com/netdiscover-scanner/netdiscover

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf tar:bz2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	sbin/netdiscover \
		share/man/man8/netdiscover.8.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/netdiscover

.include <bsd.port.mk>
