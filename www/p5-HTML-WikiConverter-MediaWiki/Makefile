# New ports collection makefile for:	p5-HTML-WikiConverter-MediaWiki
# Date created:				2006/06/27
# Whom:	      				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-WikiConverter-MediaWiki
PORTVERSION=	0.53
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	Convert HTML to MediaWiki markup

BUILD_DEPENDS=	p5-HTML-WikiConverter>=0.60:${PORTSDIR}/www/p5-HTML-WikiConverter \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::WikiConverter::MediaWiki.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.x or later due to Unicode escapes
.endif

.include <bsd.port.post.mk>
