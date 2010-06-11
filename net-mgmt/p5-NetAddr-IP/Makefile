# New ports collection makefile for:	p5-NetAddr-IP
# Date created:				12 July 2000
# Whom:					Christopher N. Harrell <cnh@ivmg.net>
#
# $FreeBSD$
#

PORTNAME=	NetAddr-IP
PORTVERSION=	4.02.8
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.([0-9])$/\1/}

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module for working with IP addresses and blocks thereof

PERL_CONFIGURE=	yes

MAN3=		NetAddr::IP.3 \
	NetAddr::IP::Lite.3 \
	NetAddr::IP::Util.3 \
	NetAddr::IP::UtilPP.3

post-patch:
	${PERL} -ni -e 'print unless /^=head1/../^=cut/' ${WRKSRC}/Lite/Util/Makefile.PL

.include <bsd.port.mk>
