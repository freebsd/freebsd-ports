# New ports collection makefile for:	p5-Google-SAML-Request
# Date created:		2009-08-05
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Google-SAML-Request
PORTVERSION=	0.04
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Create or parse Google\'s SAML requests

RUN_DEPENDS=	p5-TimeDate>0:${PORTSDIR}/devel/p5-TimeDate \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>0:${PORTSDIR}/textproc/p5-XML-Simple

PERL_CONFIGURE=	yes

MAN3=		Google::SAML::Request.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500903
RUN_DEPENDS+=	p5-IO-Compress>=2.017:${PORTSDIR}/archivers/p5-IO-Compress
.endif

.include <bsd.port.post.mk>
