PORTNAME=	wmscript
DISTVERSION=	1.0
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://krapplets.cream.org/linux/

MAINTAINER=	ip@unixway.org
COMMENT=	System monitoring dockapp for Window Maker

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake xorg
USE_XORG=	x11 xext xpm

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
WRKSRC=		${WRKDIR}/${PORTNAME}.app

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${BUILD_WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HINTS ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/${PORTNAME}rc.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
