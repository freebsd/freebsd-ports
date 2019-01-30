# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	enet
PORTVERSION=	1.3.14
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://enet.bespin.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and robust communication library based on UDP

LICENSE=	MIT

USES=		pathfix libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
	@(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
