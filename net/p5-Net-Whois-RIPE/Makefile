# ex:ts=8
# Ports collection makefile for:	p5-Net-Whois-RIPE
# Date created:			Sep 11, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-Whois-RIPE
PORTVERSION=	1.20
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Implementation of RIPE Whois

PERL_CONFIGURE=	yes

MAN3=	Net::Whois::RIPE::Iterator.3 \
	Net::Whois::RIPE::Object.3 \
	Net::Whois::RIPE.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/IO.pm:${PORTSDIR}/devel/p5-IO
.endif

.include <bsd.port.post.mk>
