# New ports collection makefile for:	p5-Text-RecordParser
# Date created:				Nov 23 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Text-RecordParser
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@thegler.dk
COMMENT=	Read record-oriented files

BUILD_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::RecordParser.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		"requires perl 5.6.x or later. Install lang/perl5 and try again"
.endif

.include <bsd.port.post.mk>
