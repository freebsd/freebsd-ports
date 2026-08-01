PORTNAME=	chomsky
DISTVERSION=	2.3
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/ctrlcctrlv/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	Chomsky.otf
EXTRACT_SUFX=
DIST_SUBDIR=	fonts/${PORTNAME}/${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	New York Times masthead, reimagined as a full font
WWW=		https://github.com/ctrlcctrlv/chomsky

LICENSE=	OFL11

USES=		fonts

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${FONTSDIR}/Chomsky.otf

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${_DISTDIR}/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
