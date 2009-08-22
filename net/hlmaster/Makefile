# New ports collection makefile for:	HL Master
# Date created:				Mon Jul  9 02:40:56 EDT 2001
# Whom:					pat@databits.net
#
# $FreeBSD$
#

PORTNAME=	hlmaster
PORTVERSION=	0.9.3
CATEGORIES=	net games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Half-Life game master server daemon

GNU_CONFIGURE=	yes

MAN1=		${PORTNAME}.1 ${PORTNAME}.gameserver.1 \
		${PORTNAME}.filter.1 ${PORTNAME}.list.1

pre-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} -e 's|CXXFLAGS = -O2 -Wall||'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/*.list \
		${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/examples/woncomm.lst \
		${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif #NOPORTDOCS

.include <bsd.port.mk>
