# New ports collection makefile for:	ipfw2dshield
# Date created:				8 June 2004
# Whom:					Frank W. Josellis <frank@dynamical-systems.org>
#
# $FreeBSD$
#

PORTNAME=	ipfw2dshield
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	http://www.dynamical-systems.org/ipfw/

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	A DShield client for ipfw logs

USE_REINPLACE=	yes

PORTDOCS=	CHANGES README.html README.txt

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/ipfw2dshield

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
