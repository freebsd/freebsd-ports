# New ports collection makefile for: Utility "mapchan" of SCO Unix
# Date created:   17 February 2004
# Whom:    Konstantin Reznichenko <kot@premierbank.dp.ua>
#
# $FreeBSD$
#

PORTNAME=	mapchan
PORTVERSION=	1.4
CATEGORIES=	sysutils converters
MASTER_SITES=	http://www.iceb.vinnitsa.com/download/

MAINTAINER=	kot@premierbank.dp.ua
COMMENT=	Implementation of the utility "mapchan" from SCO Unix

USE_BZIP2=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

ETCDAT=		*.map default.sample

MAN8=		mapchan.8

PORTDOCS=	README

pre-patch:
	@${CP} ${WRKSRC}/doc/mapchan.F ${WRKSRC}/doc/mapchan.8
	@${CP} ${WRKSRC}/examples/default ${WRKSRC}/examples/default.sample

pre-build:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" ${WRKSRC}/mapchan.c

post-install:
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${ETCDAT:S|^|${WRKSRC}/examples/|} ${PREFIX}/etc/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/mapchan.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
