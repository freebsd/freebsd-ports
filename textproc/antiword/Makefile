# New ports collection makefile for:	antiword
# Date created:				8 June 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	antiword
PORTVERSION=	0.32
CATEGORIES=	textproc
MASTER_SITES=	http://www.winfield.demon.nl/linux/

MAINTAINER=	leeym@leeym.com

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION}

MAN1=		antiword.1

post-patch:
	@${PERL5} -pi -e 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/antiword.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/antiword ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/kantiword ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/Docs/antiword.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/Resources/* ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
