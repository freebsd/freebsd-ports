# New ports collection makefile for:	perlsh
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	perlsh
PORTVERSION=	1.8
CATEGORIES=	shells perl5
MASTER_SITES=	http://www.cpan.org/authors/id/G/GR/GREGOR/
DISTNAME=	psh-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	New shell made entirely out of a Perl script

PERL_CONFIGURE=	yes

MAN1=	psh.1 pshcomplete.1 pshconfig.1 pshdevel.1

MAN3=	Psh::Completion.3 \
	Psh::Joblist.3 \
	Psh::Locale.3 \
	Psh::Locale::Default.3 \
	Psh::OS.3 \
	Psh::OS::Win.3 \
	Psh::Parser.3 \
	Psh::PerlEval.3 \
	Psh::Strategy.3 \
	Psh::StrategyBunch.3

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
