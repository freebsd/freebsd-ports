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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	${PORTNAME:L} Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Net::Whois::RIPE::Iterator.3 \
	Net::Whois::RIPE::Object.3 \
	Net::Whois::RIPE.3

.include <bsd.port.mk>
