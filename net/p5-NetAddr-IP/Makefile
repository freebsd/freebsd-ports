# New ports collection makefile for:	p5-NetAddr-IP
# Date created:				12 July 2000
# Whom:					Christopher N. Harrell <cnh@ivmg.net>
#
# $FreeBSD$
#

PORTNAME=	NetAddr-IP
PORTVERSION=	3.02
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	NetAddr
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		NetAddr::IP.3

post-patch:
	${PERL} -pi -e 's/\r//;' \
		-e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /require 5/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/IP.pm

.include <bsd.port.mk>
