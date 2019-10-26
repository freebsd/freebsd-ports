# $FreeBSD$

PORTNAME=	monoid
DISTVERSIONPREFIX=	v
DISTVERSION=	0.61
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/larsenwork/monoid/raw/${RELEASE_HASH}/
DISTFILES=	${FONTNAME}${EXTRACT_SUFX} \
		${FONTNAME}-Tight${EXTRACT_SUFX} \
		${FONTNAME}-HalfTight${EXTRACT_SUFX} \
		${FONTNAME}-HalfLoose${EXTRACT_SUFX} \
		${FONTNAME}-Loose${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}-${DISTVERSIONFULL}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Coding font with alternates, ligatures and contextual positioning

# The license is in the README file, which is not downloaded.
LICENSE=	MIT OFL11
LICENSE_COMB=	dual

USES=		fonts zip

FONTNAME=	Monoid

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

RELEASE_HASH=	2db2d289f4e61010dd3f44e09918d9bb32fb96fd

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*ttf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
