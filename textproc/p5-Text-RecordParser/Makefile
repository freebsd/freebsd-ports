# New ports collection makefile for:	p5-Text-RecordParser
# Date created:				Nov 23 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Text-RecordParser
PORTVERSION=	1.1.2
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Read record-oriented files

BUILD_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Text/TabularDisplay.pm:${PORTSDIR}/textproc/p5-Text-TabularDisplay \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		tablify.1 tabmerge.1
MAN3=		Text::RecordParser.3 \
		Text::RecordParser::Tab.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires Perl 5.8 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
