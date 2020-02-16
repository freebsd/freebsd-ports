# Created by: fenner
# $FreeBSD$

PORTNAME=	rtptools
DISTVERSION=	1.22
CATEGORIES=	net mbone

MAINTAINER=	se@FreeBSD.org
COMMENT=	Set of tools to record, playback, and monitor RTPv2 data streams

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	irtlab

PORTSCOUT=	limit:^\d.*

.for f in multidump multiplay rtpdump rtpplay rtpsend rtptrans
PLIST_FILES+=	bin/${f}
PLIST_FILES+=	man/man1/${f}.1.gz
.endfor

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md ChangeLog.html rtptools.html

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} html
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
