# ex:ts=8
# Ports collection makefile for:	p5-Net-Whois-RIPE
# Date created:			Sep 11, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-Whois-RIPE
PORTVERSION=	1.19
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Implementation of RIPE Whois

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/IO.pm:${PORTSDIR}/devel/p5-IO

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Net::Whois::RIPE::Iterator.3 \
	Net::Whois::RIPE::Object.3 \
	Net::Whois::RIPE.3

.include <bsd.port.mk>
