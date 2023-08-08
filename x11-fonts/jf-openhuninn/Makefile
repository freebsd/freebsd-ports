PORTNAME=	jf-openhuninn
PORTVERSION=	2.0
MASTER_SITES=	https://github.com/justfont/open-huninn-font/releases/download/v${PORTVERSION}/
CATEGORIES=	x11-fonts
DISTFILES=	jf-openhuninn-${PORTVERSION}.ttf
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	jf Open Huninn by justfont
WWW=		https://justfont.com/huninn/ \
		https://github.com/justfont/open-huninn-font

LICENSE=	OFL11

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/jf-openhuninn-${PORTVERSION}.ttf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${DISTDIR}/jf-openhuninn-${PORTVERSION}.ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
