# New ports collection makefile for:	p5-HTML-WikiConverter
# Date created:				2005/12/08
# Whom:	      				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-WikiConverter
PORTVERSION=	0.61
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	An HTML to wiki markup converter

BUILD_DEPENDS=	p5-Class-Data-Inheritable>=0.02:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		p5-Params-Validate>=0.77:${PORTSDIR}/devel/p5-Params-Validate \
		p5-CSS>=0:${PORTSDIR}/textproc/p5-CSS \
		p5-HTML-Parser>=3.34:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTML-Tagset>=3.04:${PORTSDIR}/www/p5-HTML-Tagset \
		p5-HTML-Tree>=3.18:${PORTSDIR}/www/p5-HTML-Tree \
		p5-URI>=1.35:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		html2wiki.1
MAN3=		HTML::WikiConverter.3 HTML::WikiConverter::Dialects.3 \
		HTML::WikiConverter::Normalizer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.x or later due to Unicode escapes
.endif

.include <bsd.port.post.mk>
