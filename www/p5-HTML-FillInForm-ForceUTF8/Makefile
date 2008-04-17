# New ports collection makefile for:	p5-HTML-FillInForm-ForceUTF8
# Date created:		2007-06-05
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	HTML-FillInForm-ForceUTF8
PORTVERSION=	0.02
CATEGORIES=	www
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cherry@trombik.org
COMMENT=	FillInForm with utf8 encoding

RUN_DEPENDS=	p5-HTML-FillInForm>0:${PORTSDIR}/www/p5-HTML-FillInForm \
	p5-Encode>0:${PORTSDIR}/converters/p5-Encode
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	HTML::FillInForm::ForceUTF8.3

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
