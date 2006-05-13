# New ports collection makefile for: Utility "mapchan" of SCO Unix
# Date created:   17 February 2004
# Whom:    Konstantin Reznichenko <kot@premierbank.dp.ua>
#
# $FreeBSD$
#

PORTNAME=	mapchan
PORTVERSION=	2.0
CATEGORIES=	sysutils converters
MASTER_SITES=	http://www.iceb.vc.ukrtel.net/download/

MAINTAINER=	bsam@ipt.ru
COMMENT=	Implementation of the utility "mapchan" from SCO Unix

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_ENV=	MAPDIR=${PREFIX}/etc/${PORTNAME}

ETCDAT=		*.map default.sample

MAN8=		mapchan.8

PORTDOCS=	README

post-extract:
	@${CP} ${WRKSRC}/doc/mapchan.F ${WRKSRC}/doc/mapchan.8

post-patch:
	@${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM}
	@${CP} ${WRKSRC}/examples/default ${WRKSRC}/examples/default.sample
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" ${WRKSRC}/mapchan.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/mapchan.8 ${MANPREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
