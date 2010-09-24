# New ports collection makefile for:    p5-ZConf-RSS
# Date created:         2009-11-09
# Whom:                 Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-RSS
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	ZConf backed RSS fetching and viewing

BUILD_DEPENDS=	${SITE_PERL}/ZConf.pm:${PORTSDIR}/net/p5-ZConf \
		${SITE_PERL}/ZConf/GUI.pm:${PORTSDIR}/devel/p5-ZConf-GUI \
		${SITE_PERL}/XML/FeedPP.pm:${PORTSDIR}/textproc/p5-XML-FeedPP \
		${SITE_PERL}/Text/NeatTemplate.pm:${PORTSDIR}/textproc/p5-Text-NeatTemplate \
		${SITE_PERL}/HTML/FormatText/WithLinks.pm:${PORTSDIR}/textproc/p5-HTML-FormatText-WithLinks
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ZConf::RSS.3 \
		ZConf::RSS::GUI.3

.include <bsd.port.mk>
