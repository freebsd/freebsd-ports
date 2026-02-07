PORTNAME=	peersuite
DISTVERSION=	1.0
CATEGORIES=	www

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Peer to peer workspace
WWW=		https://github.com/openconstruct/Peersuite

LICENSE=	AGPLv3 MIT
LICENSE_COMB=	multi

USE_GITHUB=	yes
GH_ACCOUNT=	openconstruct
GH_PROJECT=	Peersuite

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} "-name *\.js -or -name *\.html -or -name *\.css -depth 1"
	@${MKDIR} ${STAGEDIR}${WWWDIR}/themes
	@cd ${WRKSRC}/src/themes && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}/themes "-name *\.css -or -name *\.json"
	${INSTALL_DATA} ${WRKSRC}/peerspace.png ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
