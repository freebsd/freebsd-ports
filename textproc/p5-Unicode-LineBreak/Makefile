# New ports collection makefile for:	textproc/p5-Unicode-LineBreak
# Date created:				05 February 2011
# Whom:					Olivier Girard <Olivier.Girard@univ-angers.fr>
#
# $FreeBSD$
#

PORTNAME=	Unicode-LineBreak
PORTVERSION=	1.008.2
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

# blanket update approval granted.
MAINTAINER=	Olivier.Girard@univ-angers.fr
COMMENT=	Unicode-LineBreak package

PERL_CONFIGURE=	yes
USE_PERL5=	5.8.0+

CONFIGURE_ARGS+=	--with-bundled-sombok \
			--disable-libthai

MAN3=		Unicode::LineBreak.3 \
		Unicode::GCString::JA_JP.3 \
		Text::LineFold.3 \
		Unicode::LineBreak::JA_JP.3 \
		Unicode::GCString.3 \
		Text::LineFold::JA_JP.3

.include <bsd.port.mk>
