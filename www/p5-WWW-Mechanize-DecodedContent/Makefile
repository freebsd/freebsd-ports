# New ports collection makefile for:	p5-WWW-Mechanize-DecodedContent
# Date created:		2007-12-28
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize-DecodedContent
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/M/MI/MIYAGAWA
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Decode Mech content using its HTTP response encoding

BUILD_DEPENDS=	p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-HTTP-Response-Encoding>=0:${PORTSDIR}/www/p5-HTTP-Response-Encoding
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Mechanize::DecodedContent.3

.include <bsd.port.mk>
