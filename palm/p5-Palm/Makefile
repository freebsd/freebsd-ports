# New ports collection makefile for:	p5-Palm
# Date created:				29 April 2000
# Whom:					Andrew Arensburger <arensb@ooblick.com>
#
# $FreeBSD$
#

PORTNAME=	p5-Palm
PORTVERSION=	1.1.8
CATEGORIES=	palm perl5
MASTER_SITES=	http://www.ooblick.com/software/coldsync/

MAINTAINER=	arensb@ooblick.com

USE_PERL5=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Palm::Address.3 \
		Palm::Datebook.3 \
		Palm::Mail.3 \
		Palm::Memo.3 \
		Palm::PDB.3 \
		Palm::Raw.3 \
		Palm::StdAppInfo.3 \
		Palm::ToDo.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
