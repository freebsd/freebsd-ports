# New ports collection makefile for:	HTML::StickyQuery
# Date created:				24 Jan 2002
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		HTML-StickyQuery
PORTVERSION=		0.10
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=		p5-

MAINTAINER=		svenasse@polaris.ca

BUILD_DEPENDS=		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
			${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=		${BUILD_DEPENDS}

SITE_PERL=		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=		yes

MAN3=			HTML::StickyQuery.3
MANPREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
