PORTNAME=	vncreflector
PORTVERSION=	1.2.4
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF/vnc-reflector/vnc-reflector/${PORTVERSION}
DISTNAME=	vnc_reflector-${PORTVERSION}

MAINTAINER=	paul@it.ca
COMMENT=	Multi-client VNC proxy server

USES=		jpeg
USE_RC_SUBR=	vncreflector

ALL_TARGET=	default
WRKSRC=		${WRKDIR}/vnc_reflector

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|; \
		s|gcc|${CC}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} -m0750 ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
