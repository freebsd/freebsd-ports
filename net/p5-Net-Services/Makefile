# New ports collection makefile for:	p5-Net-Services
# Date created:				Wed 23 Oct 2002
# Whom:	      				Joseph Scott <joseph@randomnetworks.com>
#
# $FreeBSD$
#

PORTNAME=	Net-Services
PORTVERSION=	1.3
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	joseph@randomnetworks.com
COMMENT=	Provides a tied interface to the /etc/services file

PERL_CONFIGURE=	YES

MAN3=		Net::Services.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
