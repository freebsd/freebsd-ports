# New ports collection makefile for:	HTML-Navigation
# Date created:				Mon Jan  1 12:02:56 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	HTML-Navigation
PORTVERSION=	0.26
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/CGI/Base.pm:${PORTSDIR}/www/p5-CGI-modules \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTML::Navigation.3

.include <bsd.port.mk>
