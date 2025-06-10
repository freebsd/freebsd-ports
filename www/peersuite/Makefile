PORTNAME=	peersuite
DISTVERSION=	0.0.3
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
	${CP} ${WRKSRC}/*.js ${WRKSRC}/*.html ${WRKSRC}/*.png ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
