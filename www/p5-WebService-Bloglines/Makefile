# ex:ts=8
# Ports collection makefile for:	WebService::Bloglines
# Date created:			Nov 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	WebService-Bloglines
PORTVERSION=	0.12
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WebService
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy-to-use Interface for Bloglines Web Services

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS \
		${SITE_PERL}/XML/RSS/LibXML.pm:${PORTSDIR}/textproc/p5-XML-RSS-LibXML \
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.1+

MAN3=	WebService::Bloglines.3

.include <bsd.port.mk>
