# New ports collection makefile for:	p5-Text-Capitalize
# Date created:				24 Nov 2005
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	Text-Capitalize
PORTVERSION=	0.5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Capitalize strings ("to WORK AS titles" becomes "To Work as Titles")

PERL_CONFIGURE=	yes

MAN3=		Text::Capitalize.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl5.6
.endif

.include <bsd.port.post.mk>
