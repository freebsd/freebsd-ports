# New ports collection makefile for:	p5-HTML-Template-Expr
# Date Created:				2001/11/28
# Whom:					nork@cityfujisawa.ne.jp
#
# $FreeBSD$
#

PORTNAME=	HTML-Template-Expr
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	nork@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Text/Balanced.pm:${PORTSDIR}/textproc/p5-Text-Balanced \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::Template::Expr.3

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
