# New ports collection makefile for:	p5-WWW-Search-Google
# Date created:				8 July 2001
# Whom:					Tom Hukins <tom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search-Google
PORTVERSION=	0.22
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl WWW::Search class for searching Google

BUILD_DEPENDS=	${SITE_PERL}/WWW/Search.pm:${PORTSDIR}/www/p5-WWW-Search \
		${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite \
		${SITE_PERL}/Net/Google.pm:${PORTSDIR}/net/p5-Net-Google
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e '$$_="" if /no warnings/;' \
		${WRKSRC}/Google.pm

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWW::Search::Google.3

.include <bsd.port.mk>
