# New ports collection makefile for:  apertium
# Date created:                14 April 2009
# Whom:                        Mykola Dzham <freebsd@levsha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	apertium
PORTVERSION=	3.1.1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	freebsd@levsha.org.ua
COMMENT=	A toolbox to build shallow-transfer machine translation systems

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		xslt:${PORTSDIR}/textproc/libxslt \
		lttoolbox3:${PORTSDIR}/textproc/lttoolbox \
		pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack pkgconfig

MAN1=	apertium-deshtml.1 apertium-desodt.1 apertium-despptx.1 \
        apertium-desrtf.1 apertium-destxt.1 apertium-deswxml.1 \
        apertium-desxlsx.1 apertium-filter-ambiguity.1 \
	apertium-gen-deformat.1 apertium-gen-lextorbil.1 \
	apertium-gen-lextormono.1 apertium-gen-modes.1 \
	apertium-gen-reformat.1 apertium-gen-stopwords-lextor.1 \
	apertium-gen-wlist-lextor-translation.1 apertium-gen-wlist-lextor.1 \
	apertium-interchunk.1 apertium-lextor.1 apertium-multiple-translations.1 \
	apertium-postchunk.1 apertium-preprocess-corpus-lextor.1 \
	apertium-preprocess-transfer.1 apertium-pretransfer.1 \
	apertium-rehtml.1 apertium-reodt.1 apertium-repptx.1 \
	apertium-rertf.1 apertium-retxt.1 apertium-rewxml.1 apertium-rexlsx.1 \
	apertium-tagger-apply-new-rules.1 apertium-tagger.1 apertium-transfer.1 \
	apertium-validate-acx.1 apertium-validate-dictionary.1 \
	apertium-validate-interchunk.1 apertium-validate-modes.1 \
	apertium-validate-postchunk.1 apertium-validate-tagger.1\
		apertium-validate-transfer.1 apertium-unformat.1 \
	apertium.1

.include <bsd.port.mk>
