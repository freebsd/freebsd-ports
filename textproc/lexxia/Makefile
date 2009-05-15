# New ports collection makefile for:	lexxia
# Date created:		Mar 26 2009
# Whom:			martin.dieringer@gmx.de
#
# $FreeBSD$

PORTNAME=	lexxia
PORTVERSION=	0.901
CATEGORIES=	textproc
MASTER_SITES=	http://www.limpidsoft.com/downloads/linux-1,3,02/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.3.02

MAINTAINER=	martin.dieringer@gmx.de
COMMENT=	A Multiformat Text Processor (XML, [X]HTML, LaTeX)

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/lexxia

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		does not compile: toString(long unsigned int) cannot be overloaded
.endif

.include <bsd.port.post.mk>
