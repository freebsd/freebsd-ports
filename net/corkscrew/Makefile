PORTNAME=	corkscrew
PORTVERSION=	3.1
CATEGORIES=	net
MASTER_SITES=	https://github.com/patpadgett/corkscrew/releases/download/${PORTVERSION}/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	HTTP tunnelling utility for SSH
WWW=		https://github.com/patpadgett/corkscrew

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in NEWS README.md TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
