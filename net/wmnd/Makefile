# New ports collection makefile for:	wmnd
# Date created:				29 October 2001
# Whom:					Paolo Pisati <flag@gufi.org>
#
# $FreeBSD$
#

PORTNAME=	wmnd
PORTVERSION=	0.3.3
CATEGORIES=	net
MASTER_SITES=	http://www.wingeer.org/wmnd/pkg/
DISTNAME=	wmnd_${PORTVERSION}

MAINTAINER=	flag@gufi.org

WRKSRC= 	${WRKDIR}/wmnd
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_XPM=	yes

MAN1=		wmnd.1

do-install:
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_PROGRAM} ${WRKSRC}/wmnd ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/wmnd.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/wmndrc \
		${PREFIX}/share/examples/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
.for docs in CHANGELOGS DISPLAY HINTS README
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
