# New ports collection makefile for:	p5-SWF-Chart
# Date created:				27 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	SWF-Chart
PORTVERSION=	1.4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GA/GARTH
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Perl interface to the SWF Chart generation tool

MAN3=		SWF::Chart.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw{$$1};$$1/g' \
		${WRKSRC}/lib/SWF/Chart.pm
.endif

.include <bsd.port.post.mk>
