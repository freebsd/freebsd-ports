# New ports collection makefile for:	www/p5-Catalyst-Plugin-I18N
# Date created:				2 Dec 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-I18N
PORTVERSION=	0.09
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	I18N for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=		Catalyst::Plugin::I18N.3 \
		Catalyst::Plugin::I18N::Manual.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500806
BUILD_DEPENDS+=	p5-I18N-LangTags>=0.35:${PORTSDIR}/misc/p5-I18N-LangTags
RUN_DEPENDS+=	p5-I18N-LangTags>=0.35:${PORTSDIR}/misc/p5-I18N-LangTags
.endif
.include <bsd.port.post.mk>
