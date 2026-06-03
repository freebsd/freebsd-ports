PORTNAME=	amnezia
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.11
CATEGORIES=	net net-vpn
PKGNAMESUFFIX=	-kmod

MAINTAINER=	vova@zote.me
COMMENT=	Amnezia VPN FreeBSD kernel module implementation
WWW=		https://docs.amnezia.org/documentation/amnezia-wg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		kmod uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	vgrebenschikov
GH_PROJECT=	wireguard-amnezia-kmod

PLIST_FILES=	${KMODDIR}/if_amn.ko

.include <bsd.port.mk>
