# New ports collection makefile for:	devel/p5-Text-Balanced
# Date created:				16 Sep 2001
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text-Balanced
PORTVERSION=	1.98
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract delimited text sequences from strings

PERL_CONFIGURE=	yes

MAN3=		Text::Balanced.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
post-patch:
	${REINPLACE_CMD} -e '/warnings/d' ${WRKSRC}/*.PL
	${REINPLACE_CMD} -e 's/||="<undef>"/.=""/' ${WRKSRC}/t/extqlk.t
.endif

.include <bsd.port.post.mk>
