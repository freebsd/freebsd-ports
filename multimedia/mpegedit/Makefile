# New ports collection makefile for:	mpegedit
# Date created:		Thu Aug  1 10:50:57 CDT 1996
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mpegedit
PORTVERSION=	2.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.netsw.org/graphic/movie/mpeg/mpegedit/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A program to edit encoded mpeg streams

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm

USE_X_PREFIX=	yes

post-extract:
	@${FIND} ${WRKSRC} -name '.depend' | ${XARGS} ${RM} -f

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mpeg_edit ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/manual.ps ${DOCSDIR}
.endif

.include <bsd.port.mk>
