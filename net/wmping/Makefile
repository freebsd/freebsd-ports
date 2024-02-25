PORTNAME=	wmping
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	net windowmaker
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	serg@cad.kiev.ua
COMMENT=	Windowmaker dock app to display network hosts status
WWW=		https://sourceforge.net/projects/wmping/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake xorg
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes

PORTDOCS=	BUGS CHANGES README TODO

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmping ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmping.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
