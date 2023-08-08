PORTNAME=	wifi-firmware-kmod
PORTVERSION=	20230508
CATEGORIES=	net

MAINTAINER=	bz@FreeBSD.org
COMMENT=	Firmware modules for WiFi NIC drivers
WWW=		https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/

RUN_DEPENDS=	\
		wifi-firmware-ath10k-kmod>0:net/wifi-firmware-ath10k-kmod \
		wifi-firmware-ath11k-kmod>0:net/wifi-firmware-ath11k-kmod \
		wifi-firmware-mt76-kmod>0:net/wifi-firmware-mt76-kmod \
		wifi-firmware-rtw88-kmod>0:net/wifi-firmware-rtw88-kmod \
		wifi-firmware-rtw89-kmod>0:net/wifi-firmware-rtw89-kmod

USES=		metaport

.include <bsd.port.mk>
