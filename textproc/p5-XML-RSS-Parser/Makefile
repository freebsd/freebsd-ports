# New ports collection makefile for:	p5-XML-RSS-Parser
# Date created:	 	04 Sep 2003
# Whom:			Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS-Parser
PORTVERSION=	0.21
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A liberal parser for RSS Feeds

BUILD_DEPENDS=	${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS

PERL_CONFIGURE=	yes

MAN3=		XML::RSS::Parser.3

.include <bsd.port.mk>
