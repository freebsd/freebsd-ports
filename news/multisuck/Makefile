# ex:ts=8
# Ports collection makefile for:	multisuck
# Date created:			Aug 11, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	multisuck
PORTVERSION=	1.0.3
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
ALL_TARGET=	msuck

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/msuck ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.sample ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
