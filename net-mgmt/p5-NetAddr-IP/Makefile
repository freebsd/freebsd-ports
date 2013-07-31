# Created by: Christopher N. Harrell <cnh@ivmg.net>
# $FreeBSD$

PORTNAME=	NetAddr-IP
PORTVERSION=	4.069
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module for working with IP addresses and blocks thereof

USES=		perl5
USE_PERL5=	patch configure

MAN3=		NetAddr::IP.3 \
	NetAddr::IP::InetBase.3 \
	NetAddr::IP::Lite.3 \
	NetAddr::IP::Util.3 \
	NetAddr::IP::UtilPP.3

post-patch:
	${PERL} -ni -e 'print unless /^=head1/../^=cut/' ${WRKSRC}/Lite/Util/Makefile.PL

.include <bsd.port.mk>
