# New ports collection makefile for:	abcm2ps
# Date created:				2003-06-27
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	abcm2ps
PORTVERSION=	3.7.21
CATEGORIES=	print audio
MASTER_SITES=	http://moinejf.free.fr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts ABC to music sheet in PostScript format

GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

PORTDOCS=	README
PLIST_FILES=	bin/abcm2ps %%DATADIR%%/fbook.fmt %%DATADIR%%/fonts.fmt \
		%%DATADIR%%/landscape.fmt %%DATADIR%%/tight.fmt
PLIST_DIRS=	%%DATADIR%%

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
