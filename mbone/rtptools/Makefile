# New ports collection makefile for:	rtptools
# Version required:	1.14
# Date created:		5 January 1998
# Whom:			fenner
#
# $FreeBSD$
#

DISTNAME=	rtptools-1.14
CATEGORIES=	mbone
MASTER_SITES=	http://www.cs.columbia.edu/~hgs/rtptools/src/

MAINTAINER=	fenner@FreeBSD.org

GNU_CONFIGURE=	yes

DOCFILES=	README CHANGES.html rtptools.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/rtptools
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/doc/rtptools
.endfor
.endif

.include <bsd.port.mk>
