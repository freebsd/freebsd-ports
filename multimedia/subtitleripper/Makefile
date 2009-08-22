# New ports collection makefile for:	Subtitle Ripper
# Date created:		Fri Oct 14 04:49:22 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	subtitleripper
DISTVERSION=	0.3-4
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-0.3-4
EXTRACT_SUFX=	.tgz

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Convert DVD subtitles into text format (subrip srt) or VobSub format

LIB_DEPENDS=	netpbm:${PORTSDIR}/graphics/netpbm \
		png:${PORTSDIR}/graphics/png
RUN_DEPENDS=	gocr:${PORTSDIR}/graphics/gocr \
		xv:${PORTSDIR}/graphics/xv \
		transcode:${PORTSDIR}/multimedia/transcode

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_JOBS_SAFE=	yes

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

.include <bsd.port.pre.mk>

##
# PLIST
##
.ifndef(NOPORTDOCS)
. for file in ${DOC_FILES}
PORTDOCS+=	${file}
. endfor
.endif
#
PLIST_DIRS+=	%%EXAMPLESDIR%%
.for file in ${EXAMPLES_FILES}
PLIST_FILES+=	%%EXAMPLESDIR%%/${file}
.endfor
#
.for file in ${PROGRAM_FILES}
PLIST_FILES+=	bin/${file}
.endfor
#
.for file in ${SCRIPT_FILES}
PLIST_FILES+=	bin/${file}
.endfor

##
# install
##
do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
. endfor
.endif
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES_FILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.for file in ${PROGRAM_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${SCRIPT_FILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
