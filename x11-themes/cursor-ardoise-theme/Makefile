# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	ardoise
PORTVERSION=	3.6
CATEGORIES=	x11-themes
MASTER_SITES=	https://gitlab.com/obnosim/ardoise/uploads/bb885f45d560e8cec397cc40923f8f61/:n75 \
		https://gitlab.com/obnosim/ardoise/uploads/34dece145e608381a31336735beea084/:n87 \
		https://gitlab.com/obnosim/ardoise/uploads/b5c6b8b075bcb67f9361e9bae86d5dfa/:n100 \
		https://gitlab.com/obnosim/ardoise/uploads/03012efccc0339c4281393f1c808894f/:s75 \
		https://gitlab.com/obnosim/ardoise/uploads/24b0faa40af1cba1935e92749361bc61/:s87 \
		https://gitlab.com/obnosim/ardoise/uploads/f7fdbf27029276046e37114ce9a1a1fc/:s100
PKGNAMEPREFIX=	cursor-
PKGNAMESUFFIX=	-theme
DISTFILES=	Ardoise_no_shadow_75.tar.gz:n75 Ardoise_no_shadow_87.tar.gz:n87 \
		Ardoise_no_shadow_100.tar.gz:n100 Ardoise_shadow_75.tar.gz:s75 \
		Ardoise_shadow_87.tar.gz:s87 Ardoise_shadow_100.tar.gz:s100
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}

MAINTAINER=	lightside@gmx.com
COMMENT=	Ardoise X cursor theme

LICENSE=	GPLv3

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/icons
PORTDATA=	*

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
