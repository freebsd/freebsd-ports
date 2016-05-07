# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	subtitleripper
DISTVERSION=	0.3-4
PORTREVISION=	8
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.3-4

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Convert DVD subtitles into text format (subrip srt) or VobSub format

LIB_DEPENDS=	libnetpbm.so:graphics/netpbm \
		libpng.so:graphics/png
RUN_DEPENDS=	gocr:graphics/gocr \
		xv:graphics/xv \
		transcode:multimedia/transcode

USES=		gmake tar:tgz

WRKSRC=		${WRKDIR}/${PORTNAME}

DOC_FILES=	\
		ChangeLog \
		README \
		README.gocr \
		README.srttool \
		README.subtitle2pgm \
		README.vobsub
EXAMPLES_FILES=	\
		gocrfilter_en.sed \
		gocrfilter_fr.sed \
		gocrfilter_nl.sed \
		gocrfilter_none.sed
PROGRAM_FILES=	\
		srttool \
		subtitle2pgm \
		subtitle2vobsub \
		vobsub2pgm
SCRIPT_FILES=	\
		pgm2txt

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|^(CC[[:space:]]*=).*$$|\1${CC}|' \
		-e 's|^(COPT[[:space:]]*=).*$$|\1${CFLAGS}|' \
		-e 's|^(INCLUDES[[:space:]]*:=).*$$|\1 -I${LOCALBASE}/include|' \
		-e 's|^(LIBS[[:space:]]*:=).*$$|\1 -lm -L${LOCALBASE}/lib|' \
		-e 's|-lppm|-lnetpbm|' \
		${BUILD_WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -E \
		-e 's|^(DB_PATH[[:space:]]*=).*$$|\1\$${HOME}/.db/|' \
		-e 's|^(IMAGE_VIWER[[:space:]]*=).*$$|\1${LOCALBASE}/bin/xv|' \
		-e 's|^(PATH_TO_LANGUAGE_FILTER[[:space:]]*=).*$$|\1${EXAMPLESDIR}/|' \
		-e 's|(gocr[[:space:]]+)|${LOCALBASE}/bin/\1|' \
		${WRKSRC}/pgm2txt

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOC_FILES} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}; ${INSTALL_SCRIPT} ${EXAMPLES_FILES} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ${PROGRAM_FILES} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPT_FILES} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
