# ex:ts=8
# Ports collection makefile for:	HTML::Encoding
# Date created:			Jun 5, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	HTML-Encoding
PORTVERSION=	0.53
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Determine the encoding of HTML/XML/XHTML documents

BUILD_DEPENDS=	p5-Encode>=0:${PORTSDIR}/converters/p5-Encode \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::Encoding.3

.include <bsd.port.mk>
