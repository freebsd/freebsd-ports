PORTNAME=	sflowtool
DISTVERSIONPREFIX=	v
DISTVERSION=	5.07
CATEGORIES=	net

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	sFlow capture and sFlow-to-NetFlow conversion tool

LICENSE=	InMon
LICENSE_NAME=	InMon Corp
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	sflow
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
