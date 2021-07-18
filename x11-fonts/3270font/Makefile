PORTNAME=	3270font
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/rbanffy/${PORTNAME}/releases/download/${DISTVERSIONFULL}/
DISTNAME=	3270_fonts_fd00815

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	IBM 3270 font for the nostalgic

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		fonts zip

FONTNAME=	3270

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${FONTSDIR} "! -name LICENSE.txt")

.include <bsd.port.mk>
