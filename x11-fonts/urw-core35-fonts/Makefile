# $FreeBSD$

PORTNAME=	urw-core35-fonts
DISTVERSION=	2017-08-04
CATEGORIES=	x11-fonts
MASTER_SITES=	https://git.ghostscript.com/?p=urw-core35-fonts.git;a=snapshot;h=${GIT_COMMIT};sf=tgz;dummy=/

MAINTAINER=	m.ne@gmx.net
COMMENT=	URW core35 fonts in various formats

LICENSE=	AGPLv3

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${GIT_COMMIT}

GIT_COMMIT=	91edd6e

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.otf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.afm ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.t1 ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
