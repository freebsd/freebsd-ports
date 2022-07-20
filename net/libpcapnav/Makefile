PORTNAME=	libpcapnav
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/netdude/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	libpcap wrapper library

USES=		libtool
CONFIGURE_ARGS=	--disable-gtk-doc --with-html-dir=${DOCSDIR}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|DOC_MODULE = pcapnav|DOC_MODULE =|' \
		${WRKSRC}/docs/Makefile.in

.include <bsd.port.mk>
