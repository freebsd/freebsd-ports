# New ports collection makefile for:	p5-HTML-Attributes
# Date created:				2008/08/24
# Whom:					Philip M. Gollucci <pgollucci@p6m7g8.com>
#
# $FreeBSD$

PORTNAME=	HTML-RewriteAttributes
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Simple yet powerful HTML attribute rewriting

MAKE_JOBS_SAFE=  yes

MAN3=	HTML::RewriteAttributes::Resources.3 \
  		HTML::RewriteAttributes::Links.3 \
		HTML::RewriteAttributes.3

PERL_CONFIGURE=	yes

PLIST_FILES=	%%SITE_PERL%%/HTML/RewriteAttributes.pm \
			%%SITE_PERL%%/HTML/RewriteAttributes/Resources.pm \
			%%SITE_PERL%%/HTML/RewriteAttributes/Links.pm \
			%%SITE_PERL%%/%%PERL_ARCH%%/auto/HTML/RewriteAttributes/.packlist

PLIST_DIRS=	%%SITE_PERL%%/HTML/RewriteAttributes \
			%%SITE_PERL%%/HTML \
			%%SITE_PERL%%/%%PERL_ARCH%%/auto/HTML/RewriteAttributes \
			%%SITE_PERL%%/%%PERL_ARCH%%/auto/HTML

.include <bsd.port.mk>
