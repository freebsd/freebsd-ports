# New ports collection makefile for:	HTML-Pager
# Date created:				Mon Jan  1 11:59:43 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	HTML-Pager
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for handling CGI HTML paging of arbitrary data

BUILD_DEPENDS=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Pager.3

.include <bsd.port.mk>
