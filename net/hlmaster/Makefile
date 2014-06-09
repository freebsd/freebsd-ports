# Created by: pat@databits.net
# $FreeBSD$

PORTNAME=	hlmaster
PORTVERSION=	0.9.3
CATEGORIES=	net games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Half-Life game master server daemon

GNU_CONFIGURE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} -e 's|CXXFLAGS = -O2 -Wall||'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.list ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/woncomm.lst ${STAGEDIR}${EXAMPLESDIR}
.endif #NOPORTDOCS

.include <bsd.port.mk>
