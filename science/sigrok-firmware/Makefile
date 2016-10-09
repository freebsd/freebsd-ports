# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	firmware
PORTVERSION=	20150123
CATEGORIES=	science
PKGNAMEPREFIX=	sigrok-

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Sigrok firmware

RUN_DEPENDS=	parseelf.py:science/sigrok-firmware-utils \
		${LOCALBASE}/share/sigrok-firmware/fx2lafw-cypress-fx2.fw:science/sigrok-firmware-fx2lafw

USE_GITHUB=	yes
GH_ACCOUNT=	uffejakobsen
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}
GH_TAGNAME=	2632d74

GNU_CONFIGURE=yes

USES=		autoreconf gmake

FW_FILES=	\
		LICENSE.Sigma asix-sigma-100.fw asix-sigma-200.fw asix-sigma-50.fw asix-sigma-50sync.fw \
		LICENSE.LWLA sysclk-lwla1034-extneg.rbf sysclk-lwla1034-extpos.rbf sysclk-lwla1034-int.rbf sysclk-lwla1034-off.rbf

PLIST_FILES=	\
		${FW_FILES:S,^,share/sigrok-firmware/,} \

post-install:
	${INSTALL_DATA} ${WRKSRC}/asix-sigma/LICENSE.Sigma ${STAGEDIR}${PREFIX}/share/sigrok-firmware
	${INSTALL_DATA} ${WRKSRC}/sysclk-lwla/LICENSE.LWLA ${STAGEDIR}${PREFIX}/share/sigrok-firmware

.include <bsd.port.mk>
