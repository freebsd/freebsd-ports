# New ports collection makefile for:	ranlib
# Date created:		06 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ranlib
PORTVERSION=	1.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/random/
DISTNAME=	ranlib.c

MAINTAINER=	tg@FreeBSD.org
COMMENT=	Library of Routines for Random Number Generation

INSTALLS_SHLIB=	yes
MAKE_ENV=	NOPROFILE=true
WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include <bsd.port.pre.mk>

post-extract:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ranlib
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/ranlib
.endif
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libranlib.so.1.0 ${PREFIX}/lib/libranlib.so
.endif

.include <bsd.port.post.mk>
