# New ports collection makefile for:	mmr
# Version required:			1.5.2
# Date created:				23 October 1997
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

DISTNAME=		mmr-1.5.2
CATEGORIES=		mail
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			http://www.devolution.com/~slouken/projects/mmr/
MASTER_SITE_SUBDIR=	system/mail/mua

MAINTAINER=		andy@icc.surw.chel.su

ALL_TARGET=

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/mmr ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/examples/mmr
	@ ${INSTALL_DATA} ${WRKSRC}/DOT-mmrc ${PREFIX}/share/examples/mmr/dot.mmrc.sample

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/mmr
.for file in BUGS CHANGES COPYING Copyright Features README TODO
	@ ${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/mmr
.endfor
.endif

.include <bsd.port.mk>
