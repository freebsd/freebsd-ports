# New ports collection makefile for:    cw
# Date created:		4 December 2006
# Whom:			Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	cw
PORTVERSION=	1.0.14
CATEGORIES=	sysutils
MASTER_SITES=	http://cwrapper.sourceforge.net/ \
		http://www.fakehalo.us/cw/ \
		http://dryice.name/computer/FreeBSD/distfiles/

MAINTAINER=	dryice@dryice.name
COMMENT=	A non-intrusive color wrapper for common commands

GNU_CONFIGURE=	yes
MAN1=		cw.1 cwe.1 cwu.1
MANCOMPRESSED=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGES CONTRIB COPYING FILES INSTALL PLATFORM README \
		VERSION
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
