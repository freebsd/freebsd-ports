# New ports collection makefile for:	p5-WWW-Search-Google
# Date created:				8 July 2001
# Whom:					Tom Hukins <tom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search-Google
PORTVERSION=	0.20
PORTEPOCH=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/WWW/Search.pm:${PORTSDIR}/www/p5-WWW-Search \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e '$$_="" if /no warnings/;' \
		${WRKSRC}/Google.pm

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWW::Search::Google.3

.include <bsd.port.mk>
