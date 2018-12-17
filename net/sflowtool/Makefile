# Created by: Gregory Edigarov <greg@bestnet.kharkov.ua>
# $FreeBSD$

PORTNAME=	sflowtool
PORTVERSION=	5.02
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	sFlow capture and sFlow-to-NetFlow conversion tool

USES=		autoreconf
GNU_CONFIGURE=	yes
USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	sflow

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
