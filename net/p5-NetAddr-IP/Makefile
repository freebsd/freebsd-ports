# New ports collection makefile for:	p5-NetAddr-IP
# Date created:				12 July 2000
# Whom:					Christopher N. Harrell <cnh@ivmg.net>
#
# $FreeBSD$
#

PORTNAME=	NetAddr-IP
PORTVERSION=	3.14
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	NetAddr
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		NetAddr::IP.3

post-patch:
	${PERL} -pi -e 's/\r//;' \
		-e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /require 5/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/IP.pm ${WRKSRC}/t/v4-badnm.t

post-build:
	@${PERL} -M5.6.0 -e '' >/dev/null 2>&1 || \
	( ${ECHO_MSG} "===>	Please note that this module provides more functionality when" && \
	${ECHO_MSG} "===>	used with perl 5.6.1 or perl 5.8.0 (both in the ports collection)." )

.include <bsd.port.mk>
