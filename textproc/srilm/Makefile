# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	srilm
PORTVERSION=	1.5.12
PORTREVISION=	2
CATEGORIES=	textproc
DISTNAME=	srilm
EXTRACT_SUFX?=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit for building and applying statistical language models

LIB_DEPENDS=	libtcl84.so:lang/tcl84

DOWNLOAD_URL?=	http://www.speech.sri.com/projects/srilm/download.html

USES=		gmake
MAKE_ENV+=	SRILM=${WRKSRC}
ALL_TARGET=	World
ONLY_FOR_ARCHS=	i386 amd64

PROGRAMS=	ngram ngram-count ngram-merge ngram-class disambig anti-ngram \
		nbest-lattice nbest-mix  nbest-optimize  nbest-pron-score \
		segment segment-nbest hidden-ngram multi-ngram \
		lattice-tool
SCRIPTS=	change-lm-vocab rescore-decipher rescore-acoustic \
		rescore-reweight rescore-minimize-wer make-batch-counts \
		merge-batch-counts make-big-lm make-multiword-pfsg \
		pfsg-from-ngram nbest-error nbest-rover align-with-tags \
		compute-sclite compare-sclite
GAWK_SCRIPTS=	add-classes-to-pfsg add-dummy-bows add-pauses-to-pfsg \
		add-ppls bytelog-to-log10 classes-to-fsm \
		combine-acoustic-scores compare-ppls compute-best-mix \
		compute-best-rover-mix compute-best-sentence-mix \
		compute-oov-rate continuous-ngram-count \
		extract-skip-probs find-reference-posteriors \
		fsm-to-pfsg get-gt-counts hits-from-log \
		log10-to-bytelog make-abs-discount make-diacritic-map \
		make-gt-discounts make-kn-discounts make-kn-counts \
		make-hiddens-lm make-lm-subset make-nbest-pfsg \
		make-ngram-pfsg make-sub-lm sort-lm \
		reverse-lm merge-nbest nbest-posteriors \
		nbest2-to-nbest1 nbest-vocab pfsg-to-dot pfsg-to-fsm \
		pfsg-vocab ppl-from-log remove-lowprob-ngrams \
		replace-words-with-classes reverse-text \
		reverse-ngram-counts sentid-to-sclite sentid-to-ctm \
		subtract-ppls uniform-classes vp2text wlat-to-dot \
		wlat-to-pfsg wlat-stats wordlat-to-lisp prettify

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=	because of license document, we suggest you fetch the source \
distribution\n\
manually.  Please access ${DOWNLOAD_URL}\n\
, follow the download instructions, download the source\n\
into ${DISTDIR}/, and then run make again.\n
.endif

do-extract:
	@${RM} -r ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@if ! (cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS} );\
	then \
	    exit 1; \
	fi

post-patch:
	@cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's,$$WRKSRC,${WRKSRC},g' \
		sbin/go.run-test
	${REINPLACE_CMD} -e 's,gcc,${CC},' -e 's,g++,${CXX},' \
		${WRKSRC}/common/Makefile.machine.freebsd

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/bin/freebsd && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${STAGEDIR}${PREFIX}/bin && \
		${INSTALL_SCRIPT} ${GAWK_SCRIPTS} ${STAGEDIR}${EXAMPLESDIR} && \
	cd ${WRKSRC}/man/man1 && \
		${INSTALL_MAN} *.1 ${STAGEDIR}${MAN1PREFIX}/man/man1 && \
	cd ${WRKSRC}/man/man3 && \
		${INSTALL_MAN} *.3 ${STAGEDIR}${MAN3PREFIX}/man/man3 && \
	cd ${WRKSRC}/man/man5 && \
		${INSTALL_MAN} *.5 ${STAGEDIR}${MAN5PREFIX}/man/man5 && \
	cd ${WRKSRC}/bin && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.post.mk>
