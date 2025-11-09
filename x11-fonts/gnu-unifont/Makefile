PORTNAME=	unifont
PORTVERSION=	17.0.03
PORTEPOCH=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	GNU/unifont/unifont-${PORTVERSION} \
		https://unifoundry.com/pub/unifont/unifont-${PORTVERSION}/font-builds/
PKGNAMEPREFIX=	gnu-
DISTFILES=	${FONTFILES:S|$|-${PORTVERSION}${FONTSUFFIX}|}
EXTRACT_ONLY=	# empty

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GNU Unicode font
WWW=		https://unifoundry.com/unifont/index.html \
		https://savannah.gnu.org/projects/unifont

LICENSE=	GPLv2+

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

FONTSDIR=	${PREFIX}/share/fonts/gnu-unifont
PLIST_FILES=	${FONTFILES:S|^|${FONTSDIR}/|:S|$|${FONTSUFFIX}|}

FONTFILES=	unifont
FONTSUFFIX=	.pcf.gz

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for i in ${FONTFILES}
	${INSTALL_DATA} ${DISTDIR}/${i}-${PORTVERSION}${FONTSUFFIX} ${STAGEDIR}${FONTSDIR}/${i}${FONTSUFFIX}
.endfor

.include <bsd.port.mk>
