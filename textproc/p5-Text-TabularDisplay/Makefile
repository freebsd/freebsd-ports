# New ports collection makefile for:	p5-Text-TabularDisplay
# Date created:				16 May 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Text-TabularDisplay
PORTVERSION=	1.18
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Display text in formatted table output

PERL_CONFIGURE=	yes

MAN3=		Text::TabularDisplay.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} <= 500503
# make PREFIX-clean under perl 5.005_03
post-configure:
	${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile
.endif
.include <bsd.port.post.mk>
