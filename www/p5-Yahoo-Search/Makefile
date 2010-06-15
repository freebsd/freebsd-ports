# New ports collection makefile for:	www/p5-Yahoo-Search
# Date created:				21 March 2007
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Yahoo-Search
PORTVERSION=	1.11.3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl interface to the Yahoo Search public API

BUILD_DEPENDS=	p5-URI>=1.54:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.835:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	Yahoo::Search.3 \
	Yahoo::Search::Request.3 \
	Yahoo::Search::Response.3 \
	Yahoo::Search::Result.3 \
	Yahoo::Search::XML.3

.include <bsd.port.mk>
