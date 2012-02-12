# Ports collection makefile for:	p5-Pod-Markdown
# Date created:			18 November, 2011
# Whom:				Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Pod-Markdown
PORTVERSION=	1.200000
CATEGORIES=	textproc devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Module to convert POD to Markdown

RUN_DEPENDS=	p5-Pod-Parser>=0:${PORTSDIR}/textproc/p5-Pod-Parser \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent

TEST_DEPENDS=	p5-Test-Difference>=0:${PORTSDIR}/devel/p5-Test-Differences

PERL_CONFIGURE=	yes

MAN1=		pod2markdown.1
MAN3=		Pod::Markdown.3

.include <bsd.port.mk>
