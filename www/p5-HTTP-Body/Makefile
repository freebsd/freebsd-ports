# ex:ts=8
# Ports collection makefile for:	p5-HTTP-Body
# Date created:			Nov 15, 2005
# Whom:				Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Body
PORTVERSION=	1.12
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	HTTP Body Parser

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep

PERL_CONFIGURE=	yes

MAN3=		HTTP::Body.3 \
		HTTP::Body::MultiPart.3 \
		HTTP::Body::OctetStream.3 \
		HTTP::Body::UrlEncoded.3 \
		HTTP::Body::XForms.3 \
		HTTP::Body::XFormsMultipart.3

.include <bsd.port.mk>
