# New ports collection makefile for:	srilm
# Date created:				Wed Dec 31 16:17:30 CST 2003
# Whom:					Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	srilm
PORTVERSION=	1.4.1
CATEGORIES=	textproc
DISTNAME=	srilm
EXTRACT_SUFX?=	.tgz

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Toolkit for building and applying statistical language models

LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83

DOWNLOAD_URL?=	http://www.speech.sri.com/projects/srilm/download.html

USE_GMAKE=	yes
MAKE_ENV+=	SRILM=${WRKSRC}
ALL_TARGET=	World
ONLY_FOR_ARCHS=	i386
USE_REINPLACE=	yes
NO_PACKAGE=	"not yet"

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
MAN1=		ngram.1 ngram-count.1 ngram-class.1 ngram-merge.1 disambig.1 \
		nbest-lattice.1 nbest-optimize.1 nbest-mix.1 \
		nbest-pron-score.1 segment.1 segment-nbest.1 hidden-ngram.1 \
		anti-ngram.1 multi-ngram.1 lattice-tool.1 training-scripts.1 \
		lm-scripts.1 ppl-scripts.1 pfsg-scripts.1 nbest-scripts.1 \
		select-vocab.1
MAN3=		Prob.3 Vocab.3 LM.3 File.3
MAN5=		ngram-format.5 nbest-format.5 classes-format.5 \
		pfsg-format.5 wlat-format.5

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
ECHO_MSG=/usr/bin/printf
IGNORE=	:\n\
Because of license document, we suggest you fetch the source distribution\n\
manually.  Please access ${DOWNLOAD_URL}\n\
, follow the download instructions, download the source\n\
into ${DISTDIR}/, and then run make again.\n
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@if ! (cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS} );\
	then \
	    exit 1; \
	fi

post-patch:
	@cd ${WRKSRC} && \
	${REINPLACE_CMD} -e 's,$$WRKSRC,${WRKSRC},g' \
		test/go.run-test

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/bin/freebsd && \
		${INSTALL_PROGRAM} ${PROGRAMS} ${PREFIX}/bin && \
		${INSTALL_SCRIPT} ${GAWK_SCRIPTS} ${EXAMPLESDIR} && \
	cd ${WRKSRC}/man/man1 && \
		${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1 && \
	cd ${WRKSRC}/man/man3 && \
		${INSTALL_MAN} ${MAN3} ${MANPREFIX}/man/man3 && \
	cd ${WRKSRC}/man/man5 && \
		${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5 && \
	cd ${WRKSRC}/bin && \
		${INSTALL_SCRIPT} ${SCRIPTS} ${EXAMPLESDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
