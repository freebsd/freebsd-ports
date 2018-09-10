# Created by: Anton Berezin <tobez@tobez.org>
# $FreeBSD$

PORTNAME=	Text-Tmpl
PORTVERSION=	0.33
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Templating system perl library

USES=		perl5
USE_PERL5=	configure patch

pre-patch:
	@${PERL} -pi -e '/OPTIMIZE|libtmpl.pod/ and $$_=""' \
		${WRKSRC}/Makefile.PL
	@${PERL} -pi -e 's/\(I32\)/(IV)/' \
		${WRKSRC}/typemap ${WRKSRC}/perl_tags.c

.include <bsd.port.mk>
