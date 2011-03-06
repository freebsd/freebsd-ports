# New ports collection makefile for:	rtptools
# Date created:		5 January 1998
# Whom:			fenner
#
# $FreeBSD$
#

PORTNAME=	rtptools
PORTVERSION=	1.18
CATEGORIES=	net mbone
MASTER_SITES=	http://www.cs.columbia.edu/IRT/software/rtptools/download/

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	A set of tools to record, playback and monitor RTPv2 data streams

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/rtpdump bin/rtpplay bin/rtpsend bin/rtptrans
DOCFILES=	README ChangeLog.html rtptools.html
PORTDOCS=	${DOCSFILES}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
