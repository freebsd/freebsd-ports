# New ports collection makefile for:	dcdflib
# Date created:		08 September 1998
# Whom:			Anton Berezin <tobez@plab.ku.dk>
#
# $FreeBSD$
#

PORTNAME=	dcdflib.c
PORTVERSION=	1.1
CATEGORIES=	math
MASTER_SITES=	ftp://odin.mda.uth.tmc.edu/pub/source/

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Library of C Routines for Cumulative Distribution Functions

WRKSRC=		${WRKDIR}/dcdflib.c/src

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dcdflib
	@${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.chs ${PREFIX}/share/doc/dcdflib
	@${INSTALL_DATA} ${WRKSRC}/../doc/dcdflib.fdoc ${PREFIX}/share/doc/dcdflib
	@${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/dcdflib
.endif
.if ${PORTOBJFORMAT} == "aout"
	@${LN} -sf libdcdflib.so.1.1 ${PREFIX}/lib/libdcdflib.so
.endif

.include <bsd.port.post.mk>
