# Created by: Dmitry Sivachenko <demon@FreeBSD.org>
# $FreeBSD$

PORTNAME=	irstlm
PORTVERSION=	5.80.03
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}/${PORTNAME}/${PORTNAME}-5.80
EXTRACT_SUFX=	.tgz

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The IRST Language Modeling Toolkit

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_PERL5=	run
USE_GCC=	4.7+
USE_AUTOTOOLS=	libtoolize aclocal autoconf automake
AUTOMAKE_ARGS=	--add-missing
USES=		shebangfix
SHEBANG_FILES=	scripts/add-start-end.sh scripts/lm-stat.pl scripts/sort-lm.pl scripts/build-lm-qsub.sh scripts/mdtsel.sh scripts/split-dict.pl scripts/build-lm.sh scripts/merge-sublm.pl scripts/split-ngt.sh scripts/build-sublm.pl scripts/ngram-split.pl scripts/goograms2ngrams.pl scripts/rm-start-end.sh

.include <bsd.port.mk>
