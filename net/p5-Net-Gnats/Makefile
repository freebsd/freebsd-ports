# ex:ts=8
# Ports collection makefile for:	Net-Gnats
# Date created:			May 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-Gnats
PORTVERSION=	0.05
CATEGORIES=	net databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:S/$/:cpan/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	Net/:cpan \
			gnatsperl/:sf
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:cpan \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl interface to GNU Gnats daemon

PERL_CONFIGURE=	yes

MAN3=	Net::Gnats.3 Net::Gnats::PR.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6.0 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
