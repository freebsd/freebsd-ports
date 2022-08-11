PORTNAME=	ferrite-core
PORTVERSION=	2.02
CATEGORIES=	x11-fonts

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Geometric shaped font lending it a futurist look

LICENSE=	OFL11
LICENSE_FILE=	${WRKSRC}/OFL.txt

USES=		fonts
USE_GITHUB=	yes
GH_ACCOUNT=	froyotam

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fonts/otf/*.otf ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
