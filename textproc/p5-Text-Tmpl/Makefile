# New ports collection makefile for:	textproc/p5-Text-Tmpl
# Date created:				31 December 2000
# Whom:					Anton Berezin <tobez@tobez.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Tmpl
PORTVERSION=	0.23
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@tobez.org

PERL_CONFIGURE=	yes

MAN3=		template_syntax.3 Text::Tmpl.3 template_extend.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

pre-patch:
	@${PERL} -pi -e '/OPTIMIZE|libtmpl.pod/ and $$_=""' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
