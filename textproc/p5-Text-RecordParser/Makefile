# New ports collection makefile for:	p5-Text-RecordParser
# Date created:				Nov 23 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Text-RecordParser
PORTVERSION=	1.4.0
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Read record-oriented files

BUILD_DEPENDS=	${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Text/TabularDisplay.pm:${PORTSDIR}/textproc/p5-Text-TabularDisplay \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Readonly>=0:${PORTSDIR}/devel/p5-Readonly \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN1=		tablify.1 tabmerge.1 tab2graph.1
MAN3=		Text::RecordParser.3 \
		Text::RecordParser::Tab.3 \
		Text::RecordParser::Object.3

.include <bsd.port.mk>
