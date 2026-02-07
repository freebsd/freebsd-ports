PORTNAME=	rkbin
PORTVERSION=	v0.3
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/manu

MAINTAINER=	uboot@FreeBSD.org
COMMENT=	Rockchip Binary blobs
WWW=		https://github.com/rockchip-linux/rkbin

LICENSE=	UNKNOWN
LICENSE_NAME=	rockchip
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=	tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	share/${PORTNAME}/rk35/rk3566_ddr_1056MHz_v1.23.bin \
		share/${PORTNAME}/rk35/rk3568_bl31_v1.45.elf \
		share/${PORTNAME}/rk35/rk3588_ddr_lp4_2112MHz_lp5_2400MHz_v1.18.bin \
		share/${PORTNAME}/rk35/rk3588_bl31_v1.47.elf

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/${PORTNAME}/rk35
	${INSTALL_DATA} ${WRKSRC}/rk3566_ddr_1056MHz_v1.23.bin ${STAGEDIR}/${PREFIX}/share/${PORTNAME}/rk35/
	${INSTALL_DATA} ${WRKSRC}/rk3568_bl31_v1.45.elf ${STAGEDIR}/${PREFIX}/share/${PORTNAME}/rk35/
	${INSTALL_DATA} ${WRKSRC}/rk3588_ddr_lp4_2112MHz_lp5_2400MHz_v1.18.bin ${STAGEDIR}/${PREFIX}/share/${PORTNAME}/rk35/
	${INSTALL_DATA} ${WRKSRC}/rk3588_bl31_v1.47.elf ${STAGEDIR}/${PREFIX}/share/${PORTNAME}/rk35/

.include <bsd.port.mk>
