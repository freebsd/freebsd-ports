# New ports collection makefile for:	net/p5-Net-DNS-ZoneFile
# Date created:				11 June 2002
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-DNS-ZoneFile
PORTVERSION=	1.02
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/Net/DNS/RR.pm:${PORTSDIR}/net/p5-Net-DNS \
		${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/NetAddr/IP.pm:${PORTSDIR}/net/p5-NetAddr-IP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Net::DNS::ZoneFile.3

post-patch:
	${PERL} -pi -e 's/^\s*our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /require 5/;' \
		-e '$$_="" if /^\s*(use|no)\s+warnings;\s*$$/;' \
		${WRKSRC}/ZoneFile.pm

.include <bsd.port.mk>
