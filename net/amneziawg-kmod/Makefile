PORTNAME=	amneziawg
PORTVERSION=	1.0.6
DISTVERSIONPREFIX=	v
CATEGORIES=	net net-vpn
PKGNAMESUFFIX=	-kmod

MAINTAINER=	vova@zote.me
COMMENT=	AmneziaWG FreeBSD kernel module implementation
WWW=		https://github.com/vgrebenschikov/wireguard-amnezia-kmod

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_FreeBSD_13=	Depends on kernel sources of recent FreeBSD 14 or newer

USES=		kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	vgrebenschikov
GH_PROJECT=	wireguard-amnezia-kmod

PLIST_FILES=	${KMODDIR}/if_awg.ko

.include <bsd.port.mk>
