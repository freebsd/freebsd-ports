# Created by: Gregory Edigarov <greg@bestnet.kharkov.ua>
# $FreeBSD$

PORTNAME=	sflowtool
PORTVERSION=	5.05
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	sFlow capture and sFlow-to-NetFlow conversion tool

LICENSE=	InMon
LICENSE_NAME=	InMon Corp
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-sell pkg-mirror auto-accept

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
