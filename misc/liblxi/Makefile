# $FreeBSD$

PORTNAME=	liblxi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.13
CATEGORIES=	misc

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Library for communicating with LXI compatible instruments

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxml2.so:textproc/libxml2

USES=		autoreconf libtool localbase pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	lxi-tools
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PORTDOCS=	README

OPTIONS_DEFINE=	AVAHI DOCS
OPTIONS_SUB=	yes

AVAHI_CONFIGURE_ENABLE=	avahi
AVAHI_LIB_DEPENDS=	libavahi-client.so:net/avahi-app

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
