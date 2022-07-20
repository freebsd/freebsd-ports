PORTNAME=	league-gothic
DISTVERSION=	1.601
CATEGORIES=	x11-fonts
# The .otf files are no longer comitted to the repository,
# so we need to fetch a release tarball. This is not supported
# by the current implementation of USE_GITHUB, so we overwrite
# the master site here.
MASTER_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/releases/download/${DISTVERSION}/
DISTNAME=	LeagueGothic-${DISTVERSION}

MAINTAINER=	flo@snakeoilproductions.net
COMMENT=	Revival of an old classic, Alternate Gothic \#1

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.md

USES=		fonts tar:xz
USE_GITHUB=	nodefault
GH_ACCOUNT=	theleagueof

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/static/OTF/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
