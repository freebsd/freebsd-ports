# New ports collection makefile for:	Class-Gomor
# Date created:				17 May 2006
# Whom:					Christopher Boumenot <boumenot@gmail.com>
#
# $FreeBSD$
#

PORTNAME=		Net-Write
PORTVERSION=		0.82
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=		p5-

MAINTAINER=		boumenot@gmail.com
COMMENT=		An interface to open and send raw frames to the network

PERL_CONFIGURE=	yes

MAN3=	Net::Write.3 \
	Net::Write::Layer.3 \
	Net::Write::Layer2.3 \
	Net::Write::Layer3.3 \
	Net::Write::Layer4.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=Needs perl 5.6.1 or higher, install lang/perl5.6 and try again.
.endif

.include <bsd.port.post.mk>
