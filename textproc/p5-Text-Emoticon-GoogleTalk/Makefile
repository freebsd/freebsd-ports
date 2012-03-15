# New ports collection makefile for:	Text-Emoticon-GoogleTalk
# Date created:		2006/07/21
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Text-Emoticon-GoogleTalk
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Emoticon filter of GoogleTalk

BUILD_DEPENDS=	p5-Text-Emoticon>=0:${PORTSDIR}/textproc/p5-Text-Emoticon
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::Emoticon::GoogleTalk.3

.include <bsd.port.mk>
