# Created by: Rusmir Dusko <nemysis@FreeBSD.org>

PORTNAME=	proxychains-ng
DISTVERSION=	4.16
CATEGORIES=	net security
MASTER_SITES=	https://github.com/rofl0r/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		http://ftp.barfooze.de/pub/sabotage/tarballs/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Redirect connection through proxy servers

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:xz
HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-DMONTEREY_HOOKING

CONFLICTS=	proxychains

PORTDOCS=	AUTHORS README TODO
OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e 's|libproxychains4.so|libproxychains-4.so|' \
		${WRKSRC}/src/proxyresolv

post-configure:
	@${ECHO_CMD} "PXCHAINS=proxychains" >> ${WRKSRC}/config.mak
	@${ECHO_CMD} "LDSO_PATHNAME=libproxychains-4.so" >> ${WRKSRC}/config.mak

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/proxyresolv ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/proxychains.conf \
		${STAGEDIR}${PREFIX}/etc/proxychains.conf.sample

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/proxychains
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libproxychains-4.so

.include <bsd.port.mk>
