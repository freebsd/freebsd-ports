PORTNAME=	liblxi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.18
PORTREVISION=	2
CATEGORIES=	misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for communicating with LXI compatible instruments
WWW=		https://lxi-tools.github.io

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libavahi-client.so:net/avahi-app

USES=		gnome meson pkgconfig
USE_GNOME=	libxml2
USE_GITHUB=	yes
GH_ACCOUNT=	lxi-tools
USE_LDCONFIG=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
