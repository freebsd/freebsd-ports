# New ports collection makefile for:	p5-Text-RecordParser
# Date created:				Nov 23 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Text-RecordParser
PORTVERSION=	0.08
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Read record-oriented files

BUILD_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Text/TabularDisplay.pm:${PORTSDIR}/textproc/p5-Text-TabularDisplay
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		tablify.1 tabmerge.1
MAN3=		Text::RecordParser.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
EXTRA_PATCHES=	${PATCHDIR}/5.005-RecordParser.pm \
		${PATCHDIR}/5.005-bin::tablify \
		${PATCHDIR}/5.005-t::02-filename-fh.t
.endif

.include <bsd.port.post.mk>
