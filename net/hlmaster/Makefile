# Created by: pat@databits.net
# $FreeBSD$

PORTNAME=	hlmaster
PORTVERSION=	0.9.3
CATEGORIES=	net games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Half-Life game master server daemon

USES=	dos2unix
DOS2UNIX_GLOB=	*.cpp
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} -e 's|CXXFLAGS = -O2 -Wall||'

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.list ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/woncomm.lst ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
