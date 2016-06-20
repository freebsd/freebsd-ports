# Created by: fenner
# $FreeBSD$

PORTNAME=	rtptools
PORTVERSION=	1.20
CATEGORIES=	net mbone
MASTER_SITES=	http://www.cs.columbia.edu/IRT/software/rtptools/download/

MAINTAINER=	cpm@fbsd.es
COMMENT=	Set of tools to record, playback, and monitor RTPv2 data streams

USES=	dos2unix
DOS2UNIX_GLOB=	*.c
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/rtpdump bin/rtpplay bin/rtpsend bin/rtptrans
PORTDOCS=	README ChangeLog.html rtptools.html

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
