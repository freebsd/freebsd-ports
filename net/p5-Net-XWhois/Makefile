# New ports collection makefile for:	p5-Net-XWhois
# Date created:				11 June 2001
# Whom:	      				Danny Howard <dannyman@tellme.com>
#
# $FreeBSD$
#

PORTNAME=	Net-XWhois
PORTVERSION=	0.90
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Whois Client Interface for Perl5

PERL_CONFIGURE=	YES

MAN3=		Net::XWhois.3

post-patch:
	@${FIND} ${WRKSRC} -type f -name "*.orig" -delete

.include <bsd.port.mk>
