# New ports collection makefile for:	abcm2ps
# Date created:				2003-06-27
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	abcm2ps
PORTVERSION=	5.9.14
CATEGORIES=	print audio
MASTER_SITES=	http://moinejf.free.fr/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Converts ABC to music sheet in PostScript format

GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

PORTDOCS=	Changes README deco.abc journey.abc mtunes1.abc mtunes2.abc \
		multilang.abc newfeatures.abc sample.abc sample2.abc \
		sample3.abc sample4.abc voices.abc sample3.eps features.txt \
		format.txt options.txt
PLIST_FILES=	bin/abcm2ps %%DATADIR%%/fbook.fmt %%DATADIR%%/fonts.fmt \
		%%DATADIR%%/flute.fmt %%DATADIR%%/landscape.fmt \
		%%DATADIR%%/tight.fmt
PLIST_DIRS=	%%DATADIR%%

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abcm2ps ${PREFIX}/bin/
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.fmt ${DATADIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
