# New ports collection makefile for:	vcdgear
# Date created:	 	06 January 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vcdgear
PORTVERSION=	1.6d
CATEGORIES=	multimedia
MASTER_SITES=	http://www.vcdgear.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to convert VCDs from cue/bin format to mpeg

ONLY_FOR_ARCHS=	alpha i386

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 300004
IGNORE=	"Only an ELF binary is distributed; requires FreeBSD 3.1 or later"
.endif

.if ${ARCH} == i386
DISTNAME=	${PORTNAME}16d_i386_freebsd42
.elif ${ARCH} == alpha
DISTNAME=	${PORTNAME}16d_alpha_freebsd41
.endif

NO_BUILD=	true
WRKSRC=		${WRKDIR}/vcdgear16

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vcdgear16_static ${PREFIX}/bin/vcdgear
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in faq.txt manual.txt whatsnew.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
