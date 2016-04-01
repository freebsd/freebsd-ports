# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	irstlm
PORTVERSION=	5.80.03
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-5.80

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The IRST Language Modeling Toolkit

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
USE_PERL5=	run
USES=		autoreconf libtool perl5 shebangfix tar:tgz
USE_LDCONFIG=	yes
SHEBANG_FILES=	scripts/add-start-end.sh scripts/lm-stat.pl scripts/sort-lm.pl scripts/build-lm-qsub.sh scripts/mdtsel.sh scripts/split-dict.pl scripts/build-lm.sh scripts/merge-sublm.pl scripts/split-ngt.sh scripts/build-sublm.pl scripts/ngram-split.pl scripts/goograms2ngrams.pl scripts/rm-start-end.sh

.include <bsd.port.mk>
