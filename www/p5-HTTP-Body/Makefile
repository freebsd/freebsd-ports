# ex:ts=8
# Ports collection makefile for:	p5-HTTP-Body
# Date created:			Nov 15, 2005
# Whom:				Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Body
PORTVERSION=	1.05
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTTP Body Parser

RUN_DEPENDS=	p5-YAML>=0.39:${PORTSDIR}/textproc/p5-YAML \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::Body.3 \
		HTTP::Body::MultiPart.3 \
		HTTP::Body::OctetStream.3 \
		HTTP::Body::UrlEncoded.3 \
		HTTP::Body::XForms.3 \
		HTTP::Body::XFormsMultipart.3

.include <bsd.port.mk>
