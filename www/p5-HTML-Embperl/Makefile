# New ports collection makefile for:	p5-HTML-Embperl
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-Embperl
PORTVERSION=	1.3.0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	kapr@crosswinds.net

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl

PERL_CONFIGURE=	yes
IS_INTERACTIVE=	yes

MAN3=		HTML::Embperl.3 HTML::EmbperlD.3 HTML::EmbperlObject.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
