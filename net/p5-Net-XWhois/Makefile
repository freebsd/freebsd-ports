# New ports collection makefile for:	p5-Net-XWhois
# Date created:				11 June 2001
# Whom:	      				Danny Howard <dannyman@tellme.com>
#
# $FreeBSD$
#

PORTNAME=	Net-XWhois
PORTVERSION=	0.90
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	leeym@FreeBSD.org

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::XWhois.3

post-patch:
	@find ${WRKSRC} -type f -name "*.orig" -exec rm -f "{}" ";"

.include <bsd.port.mk>
