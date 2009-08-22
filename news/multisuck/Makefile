# ex:ts=8
# Ports collection makefile for:	multisuck
# Date created:			Aug 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	multisuck
PORTVERSION=	1.0.4
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-server/conn news suck

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msuck ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.sample ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
