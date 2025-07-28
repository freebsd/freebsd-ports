PORTNAME=	netsed
PORTVERSION=	1.4
CATEGORIES=	net security
MASTER_SITES=	http://silicone.homelinux.org/release/netsed/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Alters the contents of network packets in real time
WWW=		http://silicone.homelinux.org/projects/netsed/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
MAKE_ARGS=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
