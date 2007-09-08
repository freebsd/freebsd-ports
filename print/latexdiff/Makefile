# New ports collection makefile for:   latexdiff
# Date created:                        01 Oct 2005
# Whom:                                Maxim Loginov <Zeliboba@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	latexdiff
PORTVERSION=	0.3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support
DISTNAME=	${PORTNAME}

MAINTAINER=	Zeliboba@mail.ru
COMMENT=	Determine and mark up significant differences between latex files

USE_PERL5_RUN=	yes

USE_GMAKE=	no
USE_ZIP=	yes

MAN1=		latexdiff.1 \
		latexrevise.1

PLIST_FILES=	bin/latexdiff \
		bin/latexdiff-cvs \
		bin/latexdiff-so \
		bin/latexrevise

do-build:
# empty

.include <bsd.port.mk>
