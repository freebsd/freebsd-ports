# New ports collection makefile for:    wmping
# Date created:         16 February 2004
# Whom:                 Sergey Velichkevych <serg@cad.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	wmping
PORTVERSION=	0.2.1
CATEGORIES=	net windowmaker
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	serg@cad.kiev.ua
COMMENT=	Windowmaker dock app to display network hosts status

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		wmping.1
PLIST_FILES=	bin/wmping
PORTDOCS=	BUGS CHANGES README TODO

do-install:
	${INSTALL} -c -s -m 4555 -o root -g wheel ${WRKSRC}/wmping ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wmping.1 ${PREFIX}/man/man1
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
