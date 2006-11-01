# ex:ts=8
# Ports collection makefile for:	Net-Gnats
# Date created:			May 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-Gnats
PORTVERSION=	0.06
CATEGORIES=	net databases perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnatsperl
PKGNAMEPREFIX=	p5-
EXTRACT_SUFX=	.tgz

MAINTAINER=	babak@farrokhi.net
COMMENT=	Perl interface to GNU Gnats daemon

PERL_CONFIGURE=	yes

MAN3=	Net::Gnats.3 Net::Gnats::PR.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.0 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
