PORTNAME=	unifont
PORTVERSION=	17.0.03
CATEGORIES=	x11-fonts
MASTER_SITES=	GNU/unifont/unifont-${PORTVERSION} \
		https://unifoundry.com/pub/unifont/unifont-${PORTVERSION}/font-builds/
PKGNAMEPREFIX=	gnu-
PKGNAMESUFFIX=	-otf
DISTFILES=	${FONTFILES:S|$|-${PORTVERSION}${FONTSUFFIX}|}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GNU Unicode TrueType font
WWW=		https://unifoundry.com/unifont/index.html

LICENSE=	GPLv2+

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

FONTSDIR=	${PREFIX}/share/fonts/gnu-unifont-otf
PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|:S|$|${FONTSUFFIX}|}

FONTFILES=	unifont unifont_csur unifont_upper
FONTSUFFIX=	.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for i in ${FONTFILES}
	${INSTALL_DATA} ${DISTDIR}/${i}-${PORTVERSION}${FONTSUFFIX} ${STAGEDIR}${FONTSDIR}/${i}${FONTSUFFIX}
.endfor

.include <bsd.port.mk>
