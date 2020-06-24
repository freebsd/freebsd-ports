# $FreeBSD$

PORTNAME=	linux-rkbin
DISTVERSION=	g20190719
CATEGORIES=	sysutils linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Firmware and tools for RockChip SoCs

ONLY_FOR_ARCHS=	amd64

LEGAL_TEXT=	No license

NO_BUILD=	yes

USE_GITHUB=	yes

GH_ACCOUNT=	rockchip-linux
GH_PROJECT=	rkbin
GH_TAGNAME=	890556f

post-patch:
	@${REINPLACE_CMD} -e "s|PATH=bin|PATH=${LOCALBASE}/share/${PORTNAME}/bin|" ${WRKSRC}/RKTRUST/RK3399TRUST.ini

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}/${DATADIR}/bin/rk33
	${MKDIR} ${STAGEDIR}/${DATADIR}/rktrust
	cd ${WRKSRC}/bin/rk33 && ${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR}/bin/rk33
	cd ${WRKSRC}/RKTRUST/ && ${COPYTREE_SHARE} . ${STAGEDIR}/${DATADIR}/rktrust
	cd ${WRKSRC}/tools && ${INSTALL_PROGRAM} loaderimage ${STAGEDIR}${PREFIX}/bin/rk-loaderimage
	cd ${WRKSRC}/tools && ${INSTALL_PROGRAM} trust_merger ${STAGEDIR}${PREFIX}/bin/rk-trust_merger

.include <bsd.port.mk>
