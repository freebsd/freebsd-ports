PORTNAME=	sflowtool
DISTVERSION=	6.02
CATEGORIES=	net
MASTER_SITES=	https://github.com/sflow/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	sFlow capture and sFlow-to-NetFlow conversion tool
WWW=		https://github.com/sflow/sflowtool/

LICENSE=	InMon
LICENSE_NAME=	InMon Corp
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/sflowtool

PORTDOCS=	README
PORTEXAMPLES=	sflowenable

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S|^|${WRKSRC}/scripts/|} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
