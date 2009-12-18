# New ports collection makefile for:	XML-FeedPP
# Date created:				29 May 2008
# Whom:					Oleg Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=	XML-FeedPP
PORTVERSION=	0.41
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Get an RSS file and parse it

BUILD_DEPENDS=	p5-XML-TreePP>=0.39:${PORTSDIR}/textproc/p5-XML-TreePP
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::FeedPP.3

.include <bsd.port.mk>
