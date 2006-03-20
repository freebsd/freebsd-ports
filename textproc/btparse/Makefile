# New ports collection makefile for:	btparse
# Date created:				2006-03-19
# Whom:					Kay Lehmann <kay_lehmann@web.de>
#
# $FreeBSD$
#

PORTNAME=	btparse
PORTVERSION=	0.35
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/A/AM/AMBS/${PORTNAME}

MAINTAINER=	kay_lehmann@web.de
COMMENT=	C library for parsing and processing BibTeX data files

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_PERL5_BUILD=yes

MAN3=		btparse.3 bt_language.3 bt_input.3 bt_traversal.3 \
		bt_postprocess.3 bt_macros.3 bt_split_names.3 \
		bt_format_names.3 bt_misc.3

.include <bsd.port.mk>
