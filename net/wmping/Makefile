# Created by: Sergey Velichkevych <serg@cad.kiev.ua>
# $FreeBSD$

PORTNAME=	wmping
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	net windowmaker
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	serg@cad.kiev.ua
COMMENT=	Windowmaker dock app to display network hosts status

USES=		gmake xorg
USE_XORG=	xpm
GNU_CONFIGURE=	yes

PORTDOCS=	BUGS CHANGES README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmping ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmping.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
