# New ports collection makefile for:	p5-Net-IPv4Addr
# Version required:			0.08
# Date created:				25 February 2000
# Whom:                			Brad Hendrickse <bradh@uunet.co.za>
#
# $FreeBSD$
#

DISTNAME=	Net-IPv4Addr-0.08
PKGNAME=	p5-Net-IPv4Addr-0.08
CATEGORIES=	net perl5
# not using CPAN due to them messing up the filename and version numbers
MASTER_SITES=	http://indev.insu.com/sources/

MAINTAINER=	bradh@uunet.co.za

USE_PERL5=	yes
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN1=		ipv4calc.1
MAN3=		Net::IPv4Addr.3

do-configure:

		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL PREFIX=${PREFIX}

.include <bsd.port.mk>
