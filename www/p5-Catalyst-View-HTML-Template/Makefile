# New ports collection makefile for:	www/p5-Catalyst-View-HTML-Template
# Date created:				28 May 2005
# Whom:					Gruen Christian <kiki@bsdro.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-HTML-Template
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	kiki@bsdro.org
COMMENT=	HTML::Template view class for Catalyst

BUILD_DEPENDS=	${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Catalyst::Helper::View::HTML::Template.3 \
		Catalyst::View::HTML::Template.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6. Install lang/perl5 or lang/perl5.8, and try again
.endif

.include <bsd.port.post.mk>
