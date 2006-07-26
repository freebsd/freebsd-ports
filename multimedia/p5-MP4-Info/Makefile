# New ports collection makefile for:	p5-MP4-Info
# Date created:		10-Dec-2005
# Whom:			Lars Eggert <lars.eggert@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	MP4-Info
PORTVERSION=	1.10
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MP4
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	Fetch info from MPEG-4 files

PERL_CONFIGURE=	yes

MAN3=	MP4::Info.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703 #inherited from p5-Encode
IGNORE=	requires at least Perl 5.7.3 to run.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
