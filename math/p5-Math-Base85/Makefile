# New ports collection makefile for:	math/p5-Math-Base85
# Date created:				17 Sep 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Math-Base85
PORTVERSION=	0.2
CATEGORIES=	math perl5 converters net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Math
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl extension for base 85 numbers, as referenced by RFC 1924

PERL_CONFIGURE=	yes

MAN3=		Math::Base85.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
post-patch:
	@${PERL} -pi -e 's/use Math::Big/#$$&/;' \
		     -e 's|^use constant\s*(.*?)\s*=>.s*(.*)$$|sub $$1 { $$2 }|' ${WRKSRC}/Base85.pm
.endif

.include <bsd.port.post.mk>
