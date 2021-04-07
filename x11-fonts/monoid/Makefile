PORTNAME=	monoid
DISTVERSION=	0.61
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/larsenwork/monoid/raw/${RELEASE_HASH}/:monoid \
		https://github.com/larsenwork/monoid/raw/${DISTVERSION}/Monoisome/:monoisome
DISTFILES=	${FONTNAME}${EXTRACT_SUFX}:monoid \
		${FONTNAME}-Tight${EXTRACT_SUFX}:monoid \
		${FONTNAME}-HalfTight${EXTRACT_SUFX}:monoid \
		${FONTNAME}-HalfLoose${EXTRACT_SUFX}:monoid \
		${FONTNAME}-Loose${EXTRACT_SUFX}:monoid \
		Monoisome-Regular.ttf:monoisome
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}
EXTRACT_ONLY=	${DISTFILES:M*\:monoid:S/:monoid//}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Coding font with alternates, ligatures and contextual positioning

# The license is in the README file, which is not downloaded.
LICENSE=	OFL11

USES=		fonts zip

FONTNAME=	Monoid

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RELEASE_HASH=	2db2d289f4e61010dd3f44e09918d9bb32fb96fd

post-extract:
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/Monoisome-Regular.ttf \
		${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
