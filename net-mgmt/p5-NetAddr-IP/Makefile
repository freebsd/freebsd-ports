# New ports collection makefile for:	p5-NetAddr-IP
# Date created:				12 July 2000
# Whom:					Christopher N. Harrell <cnh@ivmg.net>
#
# $FreeBSD$
#

PORTNAME=	NetAddr-IP
PORTVERSION=	3.21
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	NetAddr
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl module for working with IP addresses and blocks thereof

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		NetAddr::IP.3

post-patch:
	${PERL} -pi -e 's/\r//;' \
		-e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);\n$$1/;' \
		-e '$$_="" if /require 5/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/IP.pm ${WRKSRC}/t/v4-badnm.t ${WRKSRC}/t/v4-new.t \
		${WRKSRC}/t/v6-base.t

post-build:
	@${PERL} -M5.6.0 -e '' >/dev/null 2>&1 || \
	( ${ECHO_MSG} "===>	Please note that this module provides more functionality when" && \
	${ECHO_MSG} "===>	used with perl 5.6.1 or perl 5.8.1 (both in the ports collection)." )

.include <bsd.port.mk>
