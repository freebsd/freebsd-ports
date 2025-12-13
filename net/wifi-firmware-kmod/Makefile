PORTNAME=	wifi-firmware-kmod
PORTVERSION=	20251125
CATEGORIES=	net

MAINTAINER=	bz@FreeBSD.org
COMMENT=	Firmware modules for WiFi NIC drivers
WWW=		https://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware.git/

FLAVORS=	default release
release_PKGNAMESUFFIX=	-release

RUN_DEPENDS=	\
	wifi-firmware-iwlwifi-kmod-7000>0:net/wifi-firmware-iwlwifi-kmod@7000 \
	wifi-firmware-iwlwifi-kmod-8000>0:net/wifi-firmware-iwlwifi-kmod@8000 \
	wifi-firmware-iwlwifi-kmod-9000>0:net/wifi-firmware-iwlwifi-kmod@9000 \
	wifi-firmware-iwlwifi-kmod-22000>0:net/wifi-firmware-iwlwifi-kmod@22000 \
	wifi-firmware-iwlwifi-kmod-ax210>0:net/wifi-firmware-iwlwifi-kmod@ax210 \
	wifi-firmware-iwlwifi-kmod-bz>0:net/wifi-firmware-iwlwifi-kmod@bz \
	wifi-firmware-iwlwifi-kmod-sc>0:net/wifi-firmware-iwlwifi-kmod@sc \
	\
	wifi-firmware-rtw88-kmod-rtw8703b>0:net/wifi-firmware-rtw88-kmod@rtw8703b \
	wifi-firmware-rtw88-kmod-rtw8723d>0:net/wifi-firmware-rtw88-kmod@rtw8723d \
	wifi-firmware-rtw88-kmod-rtw8812a>0:net/wifi-firmware-rtw88-kmod@rtw8812a \
	wifi-firmware-rtw88-kmod-rtw8814a>0:net/wifi-firmware-rtw88-kmod@rtw8814a \
	wifi-firmware-rtw88-kmod-rtw8821a>0:net/wifi-firmware-rtw88-kmod@rtw8821a \
	wifi-firmware-rtw88-kmod-rtw8821c>0:net/wifi-firmware-rtw88-kmod@rtw8821c \
	wifi-firmware-rtw88-kmod-rtw8822b>0:net/wifi-firmware-rtw88-kmod@rtw8822b \
	wifi-firmware-rtw88-kmod-rtw8822c>0:net/wifi-firmware-rtw88-kmod@rtw8822c \
	\
	wifi-firmware-rtw89-kmod-rtw8851b>0:net/wifi-firmware-rtw89-kmod@rtw8851b \
	wifi-firmware-rtw89-kmod-rtw8852a>0:net/wifi-firmware-rtw89-kmod@rtw8852a \
	wifi-firmware-rtw89-kmod-rtw8852b>0:net/wifi-firmware-rtw89-kmod@rtw8852b \
	wifi-firmware-rtw89-kmod-rtw8852bt>0:net/wifi-firmware-rtw89-kmod@rtw8852bt \
	wifi-firmware-rtw89-kmod-rtw8852c>0:net/wifi-firmware-rtw89-kmod@rtw8852c \
	wifi-firmware-rtw89-kmod-rtw8922a>0:net/wifi-firmware-rtw89-kmod@rtw8922a \
	\
	wifi-firmware-mt7601u-kmod>0:net/wifi-firmware-mt7601u-kmod


.if ${FLAVOR:U} != release
RUN_DEPENDS+=	\
	wifi-firmware-ath10k-kmod-qca4019_hw10>0:net/wifi-firmware-ath10k-kmod@qca4019_hw10 \
	wifi-firmware-ath10k-kmod-qca6174_hw21>0:net/wifi-firmware-ath10k-kmod@qca6174_hw21 \
	wifi-firmware-ath10k-kmod-qca6174_hw30>0:net/wifi-firmware-ath10k-kmod@qca6174_hw30 \
	wifi-firmware-ath10k-kmod-qca9377_hw10>0:net/wifi-firmware-ath10k-kmod@qca9377_hw10 \
	wifi-firmware-ath10k-kmod-qca9887_hw10>0:net/wifi-firmware-ath10k-kmod@qca9887_hw10 \
	wifi-firmware-ath10k-kmod-qca9888_hw20>0:net/wifi-firmware-ath10k-kmod@qca9888_hw20 \
	wifi-firmware-ath10k-kmod-qca988x_hw20>0:net/wifi-firmware-ath10k-kmod@qca988x_hw20 \
	wifi-firmware-ath10k-kmod-qca9984_hw10>0:net/wifi-firmware-ath10k-kmod@qca9984_hw10 \
	wifi-firmware-ath10k-kmod-qca99x0_hw20>0:net/wifi-firmware-ath10k-kmod@qca99x0_hw20 \
	wifi-firmware-ath10k-kmod-wcn3990_hw10>0:net/wifi-firmware-ath10k-kmod@wcn3990_hw10 \
	\
	wifi-firmware-ath11k-kmod-ipq5018_hw10>0:net/wifi-firmware-ath11k-kmod@ipq5018_hw10 \
	wifi-firmware-ath11k-kmod-ipq6018_hw10>0:net/wifi-firmware-ath11k-kmod@ipq6018_hw10 \
	wifi-firmware-ath11k-kmod-ipq8074_hw20>0:net/wifi-firmware-ath11k-kmod@ipq8074_hw20 \
	wifi-firmware-ath11k-kmod-qca2066_hw21>0:net/wifi-firmware-ath11k-kmod@qca2066_hw21 \
	wifi-firmware-ath11k-kmod-qca6390_hw20>0:net/wifi-firmware-ath11k-kmod@qca6390_hw20 \
	wifi-firmware-ath11k-kmod-qca6698aq_hw21>0:net/wifi-firmware-ath11k-kmod@qca6698aq_hw21 \
	wifi-firmware-ath11k-kmod-qcn9074_hw10>0:net/wifi-firmware-ath11k-kmod@qcn9074_hw10 \
	wifi-firmware-ath11k-kmod-wcn6750_hw10>0:net/wifi-firmware-ath11k-kmod@wcn6750_hw10 \
	wifi-firmware-ath11k-kmod-wcn6855_hw20>0:net/wifi-firmware-ath11k-kmod@wcn6855_hw20 \
	\
	wifi-firmware-ath12k-kmod-qcn9274_hw20>0:net/wifi-firmware-ath12k-kmod@qcn9274_hw20 \
	wifi-firmware-ath12k-kmod-wcn7850_hw20>0:net/wifi-firmware-ath12k-kmod@wcn7850_hw20 \
	\
	wifi-firmware-mt76-kmod-mt7615>0:net/wifi-firmware-mt76-kmod@mt7615 \
	wifi-firmware-mt76-kmod-mt7915>0:net/wifi-firmware-mt76-kmod@mt7915 \
	wifi-firmware-mt76-kmod-mt7921>0:net/wifi-firmware-mt76-kmod@mt7921 \
	wifi-firmware-mt76-kmod-mt7925>0:net/wifi-firmware-mt76-kmod@mt7925 \
	wifi-firmware-mt76-kmod-mt7996>0:net/wifi-firmware-mt76-kmod@mt7996 \
	wifi-firmware-mt76-kmod-mtk_wed>0:net/wifi-firmware-mt76-kmod@mtk_wed
.endif

USES=		metaport

.include <bsd.port.mk>
