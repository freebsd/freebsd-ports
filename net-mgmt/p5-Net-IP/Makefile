# New ports collection makefile for:   p5-Net-IP
# Date created:                30 May 2002
# Whom:                        Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	Net-IP
PORTVERSION=	1.11
CATEGORIES=	net perl5 ipv6
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	fuyuki@hadaly.org

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::IP.3

post-patch:
	${PERL} -pi -e 's,/usr/local/ncc/bin,${PREFIX}/bin,' ${WRKSRC}/Makefile.PL
	${PERL} -pi -e 's,/usr/local/bin/perl5.6.0,${PERL},' ${WRKSRC}/ipcount

.include <bsd.port.mk>
