PORTNAME=	cascadia-next
PORTVERSION=	g20240828
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/microsoft/cascadia-code/releases/download/cascadia-next/
DISTFILES=	CascadiaNextJP.wght.ttf \
		CascadiaNextSC.wght.ttf \
		CascadiaNextTC.wght.ttf
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Monospaced font with programming ligatures
WWW=		https://github.com/microsoft/cascadia-code

LICENSE=	OFL11

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/CascadiaNextJP.wght.ttf \
		${FONTSDIR}/CascadiaNextSC.wght.ttf \
		${FONTSDIR}/CascadiaNextTC.wght.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${DISTDIR} && ${INSTALL_DATA} ${DISTFILES} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
