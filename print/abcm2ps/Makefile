# New ports collection makefile for:	abcm2ps
# Date created:				2003-06-27
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	abcm2ps
PORTVERSION=	3.7.15
CATEGORIES=	print audio
MASTER_SITES=	http://moinejf.free.fr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts ABC to music sheet in PostScript format

GNU_CONFIGURE=	yes
ALL_TARGET=	abcm2ps

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
