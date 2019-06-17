# $FreeBSD$

PORTNAME=	gmp-api
DISTVERSION=	58 # from config/milestone.txt of mozilla-central commit
CATEGORIES=	multimedia

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	Gecko Media Plugins API from mozilla-release

LICENSE=	APACHE20

USE_GITHUB=	yes
GH_ACCOUNT=	mozilla
GH_TAGNAME=	e393575

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/*.h ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
