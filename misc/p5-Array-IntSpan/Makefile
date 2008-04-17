# New ports collection makefile for:	p5-Array-IntSpan
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Array-IntSpan
PORTVERSION=		2.001
CATEGORIES=		misc perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-

MAINTAINER=		perl@FreeBSD.org
COMMENT=	Module for handling arrays using IntSpan techniques

PERL_CONFIGURE=		yes

MAN3=	Array::IntSpan.3 Array::IntSpan::Fields.3

post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw($$1); $$1/' ${WRKSRC}/Array/IntSpan.pm
	@${PERL} -pi -e 's/3pm/3/g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
