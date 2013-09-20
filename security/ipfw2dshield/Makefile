# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	ipfw2dshield
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	http://www.dynamical-systems.org/ipfw/

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	DShield client for ipfw logs

PORTDOCS=	CHANGES README.html README.txt

NO_STAGE=	yes
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
