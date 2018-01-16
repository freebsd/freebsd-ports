# Created by: fenner
# $FreeBSD$

PORTNAME=	rtptools
PORTVERSION=	1.21
CATEGORIES=	net mbone
MASTER_SITES=	http://www.cs.columbia.edu/IRT/software/rtptools/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of tools to record, playback, and monitor RTPv2 data streams

LICENSE=	CUL
LICENSE_NAME=	Columbia University License
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=	dos2unix
DOS2UNIX_GLOB=	*.c
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/rtpdump bin/rtpplay bin/rtpsend bin/rtptrans
PORTDOCS=	README ChangeLog.html rtptools.html

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
