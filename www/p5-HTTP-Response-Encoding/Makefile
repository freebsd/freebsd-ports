# New ports collection makefile for:	p5-HTTP-Response-Encoding
# Date created:		2007-10-27
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Response-Encoding
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Adds encoding() to HTTP::Response

BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		p5-Encode>=2.0:${PORTSDIR}/converters/p5-Encode
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		HTTP::Response::Encoding.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805
RUN_DEPENDS+=	p5-Encode>=2:${PORTSDIR}/converters/p5-Encode
.endif

.include <bsd.port.post.mk>
