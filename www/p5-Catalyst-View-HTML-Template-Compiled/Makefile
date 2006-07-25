# New ports collection makefile for:	www/p5-Catalyst-View-HTML-Template-Compiled
# Date created:				05 June 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-View-HTML-Template-Compiled
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst/ESSKAR
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	HTML::Template::Compiled View Class

BUILD_DEPENDS=	${SITE_PERL}/HTML/Template/Compiled.pm:${PORTSDIR}/www/p5-HTML-Template-Compiled \
		${SITE_PERL}/Path/Class.pm:${PORTSDIR}/devel/p5-Path-Class \
		${SITE_PERL}/Catalyst.pm:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:${PORTSDIR}/www/p5-Catalyst-Devel
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Catalyst::Helper::View::HTML::Template::Compiled.3 \
		Catalyst::View::HTML::Template::Compiled.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
