PORTNAME=	stixfonts
PORTVERSION=	2.14
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/
DISTNAME=	fonts
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	OpenType Unicode fonts for Scientific, Technical, and Math texts
WWW=		https://www.stixfonts.org/

LICENSE=	OFL11

USES=		fonts xorg zip
USE_XORG=	x11

#USE_GITHUB=	yes
GH_ACCOUNT=	stipub

WRKSRC=		${WRKDIR}/fonts
NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

FONTNAME=	STIX

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	cd ${WRKSRC} &&	${FIND} STIXTwoMath STIXTwoText -type file ! -name .DS_Store	\
		-exec ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR} \;
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
