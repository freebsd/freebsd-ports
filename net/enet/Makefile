PORTNAME=	enet
PORTVERSION=	1.3.17
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://enet.bespin.org/download/

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Simple and robust communication library based on UDP

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
