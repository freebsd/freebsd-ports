# New ports collection makefile for:	rtptools
# Version required:	1.9
# Date created:		5 January 1998
# Whom:			fenner
#
# $FreeBSD$
#

DISTNAME=	rtptools-1.9
CATEGORIES=	mbone
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/schulzrinne/rtptools/

MAINTAINER=	fenner@FreeBSD.org

MAKE_ENV=	ARCH=freebsd CC=cc

BINFILES=	rtpdump rtpplay rtpsend rtptrans
DOCFILES=	README CHANGES.html rtptools.html

do-install:
.for i in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd/${i} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/rtptools
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/rtptools
.endfor
.endif

.include <bsd.port.mk>
