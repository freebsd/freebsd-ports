# Created by: arved
# $FreeBSD$

PORTNAME=	abcm2ps
PORTVERSION=	7.8.14
CATEGORIES=	print audio
MASTER_SITES=	http://moinejf.free.fr/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Converts ABC to music sheet in PostScript format

USES=		cpe
CPE_VENDOR=	moinejf
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

PORTDOCS=	Changes README deco.abc newfeatures.abc sample.abc sample2.abc\
		sample3.abc sample4.abc voices.abc sample3.eps features.txt \
		format.txt options.txt
PLIST_FILES=	bin/abcm2ps \
		%%DATADIR%%/flute.fmt %%DATADIR%%/landscape.fmt \
		%%DATADIR%%/tight.fmt %%DATADIR%%/musicfont.fmt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/abcm2ps ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.fmt ${STAGEDIR}${DATADIR}/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
