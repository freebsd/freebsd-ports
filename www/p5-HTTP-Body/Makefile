# ex:ts=8
# Ports collection makefile for:	p5-HTTP-Body
# Date created:			Nov 15, 2005
# Whom:				Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Body
PORTVERSION=	0.6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	HTTP Body Parser

BUILD_DEPENDS=	p5-File-Temp>=0.14:${PORTSDIR}/devel/p5-File-Temp \
		p5-YAML>=0.39:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTTP::Body::OctetStream.3 \
		HTTP::Body::UrlEncoded.3 \
		HTTP::Body.3 \
		HTTP::Body::MultiPart.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500601
IGNORE=	requires at least Perl 5.6.1. Install lang/perl5, and try again
.endif
.include <bsd.port.post.mk>
