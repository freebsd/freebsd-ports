# New ports collection makefile for:	www/p5-Catalyst-Plugin-I18N
# Date created:				2 Dec 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-I18N
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/C/CH/CHANSEN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	I18N for Catalyst

BUILD_DEPENDS=	p5-Catalyst>=2.99:${PORTSDIR}/www/p5-Catalyst \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-Locale-Maketext-Simple>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::I18N.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires at least Perl 5.8. Install lang/perl5.8, and try again
.elif ${PERL_LEVEL} < 500805
BUILD_DEPENDS+=	p5-I18N-LangTags-Detect>=0:${PORTSDIR}/misc/p5-I18N-LangTags
RUN_DEPENDS+=	p5-I18N-LangTags-Detect>=0:${PORTSDIR}/misc/p5-I18N-LangTags
.endif
.include <bsd.port.post.mk>
