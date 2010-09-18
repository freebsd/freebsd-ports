# New ports collection makefile for:    cw
# Date created:		4 December 2006
# Whom:			Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	cw
PORTVERSION=	1.0.16
CATEGORIES=	sysutils
MASTER_SITES=	http://cwrapper.sourceforge.net/ \
		http://www.fakehalo.us/cw/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A non-intrusive color wrapper for common commands

GNU_CONFIGURE=	yes

MANCOMPRESSED=	yes
MAN1=		cw.1 cwe.1 cwu.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGES CONTRIB FILES INSTALL PLATFORM README VERSION
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
