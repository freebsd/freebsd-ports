# New ports collection makefile for:	textproc/p5-Text-FixedLength-Extra
# Date created:				30 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Text-FixedLength-Extra
PORTVERSION=	1.1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Various niceties for p5-Text-FixedLength lovers

BUILD_DEPENDS=	${SITE_PERL}/Text/FixedLength.pm:${PORTSDIR}/textproc/p5-Text-FixedLength
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::FixedLength::Extra.3

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		-e '$$_="" if /require 5/;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/Extra.pm

.include <bsd.port.mk>
