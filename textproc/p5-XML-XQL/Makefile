# New ports collection makefile for:	XML::XQL
# Date created:				Sat Nov 23 17:24:19 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-XQL
PORTVERSION=	0.68
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module for querying XML tree structures with XQL

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Parse/Yapp.pm:${PORTSDIR}/devel/p5-Parse-Yapp \
		${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::XQL.3 XML::XQL::DOM.3 XML::XQL::Date.3 \
		XML::XQL::Query.3 XML::XQL::Tutorial.3

.include <bsd.port.mk>
