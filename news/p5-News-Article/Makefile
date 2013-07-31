# Created by: Don Croyle <croyle@gelemna.org>
# $FreeBSD$

PORTNAME=	News-Article
PORTVERSION=	1.27
PORTREVISION=	2
CATEGORIES=	news perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Object for handling Usenet articles in mail or news form

BUILD_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	p5-Net>=0:${PORTSDIR}/net/p5-Net

USES=		perl5
USE_PERL5=	configure

MAN3=		News::Article.3 News::AutoReply.3 News::FormArticle.3 \
		News::FormReply.3

OPTIONS_DEFINE=	PGP_SIGN
OPTIONS_DEFAULT=	PGP_SIGN
PGP_SIGN_DESC=	PGP::Sign support for header signing

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGP_SIGN}
BUILD_DEPENDS+=	p5-PGP-Sign>=0:${PORTSDIR}/security/p5-PGP-Sign
RUN_DEPENDS+=	p5-PGP-Sign>=0:${PORTSDIR}/security/p5-PGP-Sign
.endif

.include <bsd.port.mk>
