PORTNAME=	intel-one-mono
DISTVERSIONPREFIX=	V
DISTVERSION=	1.2.0
CATEGORIES=	x11-fonts

MAINTAINER=	dz@dolik.dev
COMMENT=	Intel One Mono font

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/license

USES=		fonts
FONTNAME=	${PORTNAME:C/-//}
USE_GITHUB=	yes
GH_ACCOUNT=	intel

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
.for _format in otf ttf
	${INSTALL_DATA} ${WRKSRC}/fonts/${_format}/*.${_format} ${STAGEDIR}${FONTSDIR}
.endfor

.include <bsd.port.mk>
