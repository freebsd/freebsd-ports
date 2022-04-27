PORTNAME=	liblxi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.16
CATEGORIES=	misc

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Library for communicating with LXI compatible instruments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libavahi-client.so:net/avahi-app \
		libxml2.so:textproc/libxml2

USES=		meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	lxi-tools
USE_LDCONFIG=	yes

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
