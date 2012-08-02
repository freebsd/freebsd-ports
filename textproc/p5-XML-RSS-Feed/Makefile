# New ports collection makefile for:	XML::RSS::Feed
# Date created:				Aug 1, 2006
# Whom:					Cheng-Lung Sung <clsung@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS-Feed
PORTVERSION=	2.32
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Persistent XML RSS encapsulation

BUILD_DEPENDS=	p5-XML-RSS>=0:${PORTSDIR}/textproc/p5-XML-RSS \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::RSS::Feed.3 \
		XML::RSS::Headline.3 \
		XML::RSS::Headline::Fark.3 \
		XML::RSS::Headline::PerlJobs.3 \
		XML::RSS::Headline::UsePerlJournals.3

.include <bsd.port.mk>
