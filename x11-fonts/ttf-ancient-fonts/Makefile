PORTNAME=	ttf-ancient-fonts
DISTVERSION=	2.60
CATEGORIES=	x11-fonts
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	${PORTNAME}_${DISTVERSION}.orig

MAINTAINER=	ps.ports@smyrak.com
COMMENT=	Set of fonts designed for ancient languages and scripts.
WWW=		http://users.teilar.gr/~g1951d/

LICENSE=	Douros
LICENSE_NAME=	Douros-Free-Font
LICENSE_TEXT=	Fonts are free for any use; they may be opened, edited, \
		modified, regenerated, packaged and redistributed.
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

USES=		fonts tar:xz

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}.orig

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}/
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}/

.include <bsd.port.mk>
