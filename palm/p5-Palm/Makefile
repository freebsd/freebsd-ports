# New ports collection makefile for:	p5-Palm
# Date created:				29 April 2000
# Whom:					Andrew Arensburger <arensb+freebsd-ports@ooblick.com>
#
# $FreeBSD$
#

PORTNAME=	p5-Palm
PORTVERSION=	1.2.2
CATEGORIES=	palm perl5
MASTER_SITES=	http://www.ooblick.com/software/coldsync/

MAINTAINER=	arensb@ooblick.com

PERL_CONFIGURE=	YES

# Just so that the .packlist conforms to reality
NOMANCOMPRESS=	yes
MAN1=		pdbdump.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Palm::Address.3 \
		Palm::Datebook.3 \
		Palm::Mail.3 \
		Palm::Memo.3 \
		Palm::PDB.3 \
		Palm::Raw.3 \
		Palm::StdAppInfo.3 \
		Palm::ToDo.3

.include <bsd.port.mk>
