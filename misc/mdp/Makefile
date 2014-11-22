# $FreeBSD$

PORTNAME=	mdp
PORTVERSION=	0.92.3
CATEGORIES=	misc

MAINTAINER=	neel@neelc.org
COMMENT=	Command-line based markdown presentation tool

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	visit1985
GH_PROJECT=	mdp
GH_COMMIT=	ecb0976

USES=		gmake
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mdp ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
